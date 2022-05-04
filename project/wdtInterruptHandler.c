#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 250;
  static u_int second_count = 0;

  second_count++;
    drawSprite(29, 19, 0,0, spiderman_idle);
  if (second_count >= second_limit) {
    updateSpiderPos();
    second_count = 0;
  }
  
} 

