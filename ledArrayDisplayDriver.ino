#include <OctoWS2811.h>

const int ledsPerStrip = 240;
const int stripCount = 4;
const int arrayLength = ledsPerStrip*stripCount;

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup() {
  leds.begin();
  leds.show();
  Serial.begin(9600);
}
 
unsigned int integerValue=0;  // Max value is 65535
String incomingString;
 
void loop() {
  int index = 0;
  while (Serial.available()) {
    incomingString = Serial.readStringUntil(',');
    int number = (int) incomingString.toInt();
    leds.setPixel(index, number);
    leds.show();
    index++;
    Serial.println(incomingString);
  }
}

void colorWipe(int color, int wait)
{
  for (int i=0; i < leds.numPixels(); i++) {
    leds.setPixel(i, color);
    leds.show();
    delayMicroseconds(wait);
  }
}
