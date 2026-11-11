#include <bits/stdc++.h>
using namespace std;
int a, a1;
char ch1, ch2, ch3, ch4, b, b1;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> ch1 >> ch2 >> b >> a1 >> ch3 >> ch4 >> b1;
    if(a == a1) {
        cout << 1;
        if(ch1 == ch3 && ch2 == ch4) {
            cout << 1;
            if((b <= 'C' && b1 <= 'C') || (b > 'C' && b1 > 'C')) {
                cout << 1;
                if(abs(b - b1) == 1) {
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            else {
                cout << 0 << 0;
            }
        }
        else {
            cout << 0 << 0 << 0;
        }
    }
    else {
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}
