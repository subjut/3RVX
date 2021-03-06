// Copyright (c) 2015, Matthew Malensek.
// Distributed under the BSD 2-Clause License (see LICENSE.txt for details)

#pragma once

#include <string>

#include "../TinyXml2/tinyxml2.h"
#include "Skin.h"
#include "SkinInfo.h"

class Meter;
class SliderKnob;
class SoundPlayer;

struct MeterComponent;

using tinyxml2::XMLElement;

class SkinV3 : public Skin, public SkinInfo {
public:
    SkinV3(std::wstring skinXML);
    ~SkinV3();

    virtual OSDComponent *VolumeOSD();
    virtual OSDComponent *MuteOSD();
    virtual OSDComponent *EjectOSD();
    virtual OSDComponent *BrightnessOSD();

    virtual std::vector<HICON> VolumeIconset();

    virtual SliderComponent *VolumeSlider();

private:
    OSDComponent *CreateOSDComponent(char *osdType);
    SliderComponent *CreateSliderComponent(char *sliderType);
    bool PopulateMeterComponent(MeterComponent *component, XMLElement *elem);

    int DefaultUnits(XMLElement *elem);
    Gdiplus::Bitmap *Image(XMLElement *element, char *attrName);
    std::wstring ImageName(XMLElement *elem);

    std::vector<HICON> Iconset(XMLElement *elem);
    SliderKnob *Knob(XMLElement *elem);
    SoundPlayer *Sound(XMLElement *elem);

    std::vector<Meter *> Meters(XMLElement *parentElement);
    Meter *LoadMeter(XMLElement *meterXMLElement);
    Gdiplus::Font *Font(XMLElement *meterXMLElement);
    Gdiplus::StringAlignment Alignment(XMLElement *meterXMLElement);
};
