#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
int get2char() {
    int __ans = (getchar() - '0') * 10 + getchar() - '0';
    return __ans;
}
bool inl(char __c) {
    return __c >= 'A' && __c <= 'C';
}
bool inr(char __c) {
    return __c >= 'D' && __c <= 'F';
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, x1, y1, c2, x2, y2, ans[5] = {0, 0, 0, 0, 0};
    c1 = get2char();
    getchar();
    x1 = get2char();
    y1 = getchar();
    getchar();
    c2 = get2char();
    getchar();
    x2 = get2char();
    y2 = getchar();
    if (c1 == c2) {
        ans[1] = 1;
        if (x1 == x2) {
            ans[2] = 1;
            if (inl(y1) && inl(y2) || inr(y1) && inr(y2)) {
                ans[3] = 1;
                if (abs(y1 - y2) == 1) {
                    ans[4] = 1;
                }
            }
        }
    }
    for (int i = 1; i < 5; i++) {
        cout << ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
