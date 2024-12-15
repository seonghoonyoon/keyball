/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4      , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_DEL   ,
    KC_TAB   , KC_Q     , KC_W     , KC_F     , KC_P      , KC_G     ,                                  KC_J     , KC_L     , KC_U     , KC_Y     , KC_SCLN  , KC_BSLS  ,
    KC_LCTL  , KC_A     , KC_R     , KC_S     , KC_T      , KC_D     ,                                  KC_H     , KC_N     , KC_E     , KC_I     , KC_O     , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V      , KC_B     , KC_LBRC  ,              KC_RBRC, KC_K     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    _______  , KC_LCTL  , KC_LGUI  , KC_LALT, LT(1,KC_ESC),LT(2,KC_SPC),LT(3,KC_LNG1),      KC_BSPC,LT(2,KC_ENT) , _______  , _______  , _______  , KC_RALT  , KC_PSCR
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , KC_F10  , KC_F11  , KC_F12  , _______  ,                                  _______     , KC_7     , KC_8     , KC_9     , _______  , _______  ,
    _______  , _______  , KC_F7   , KC_F8   , KC_F9   , _______  ,                                  KC_EQL      , KC_4     , KC_5     , KC_6     , _______  , _______  ,
    _______  , _______  , KC_F4   , KC_F5   , KC_F6   , _______  ,                                  KC_MINUS    , KC_1     , KC_2     , KC_3     , _______  , _______  ,
    _______  , _______  , KC_F1   , KC_F2   , KC_F3   , _______  , _______  ,            _______  , S(KC_MINUS) , KC_0     , KC_DOT   , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,         _______  , _______  ,    _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    SSNP_FRE , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_PGUP  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , KC_HOME  ,             KC_END  , KC_PGDN  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  _______  , _______  , _______  , _______ , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            EE_CLR   , _______  , _______  , _______  , _______  , _______  , _______  ,
    QK_BOOT  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
