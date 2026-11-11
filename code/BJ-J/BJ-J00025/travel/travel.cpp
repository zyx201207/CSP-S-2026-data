#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string x, y, xx, yy;
    cin >> x >> xx >> y >> yy;
    if (x == y) {
        cout << 1;
        if (xx[0] == yy[0] && xx[1] == yy[1]) {
            cout << 1;
            if ((xx[2] >= 'A' && xx[2] <= 'C' && yy[2] >= 'A' && yy[2] <= 'C') || (xx[2] >= 'D' && xx[2] <= 'F' && yy[2] >= 'D' && yy[2] <= 'f')) {
                cout << 1;
                if (abs(int(xx[2] - yy[2])) == 1 && (xx[2] != 'D' && yy[2] != 'C') && (xx[2] != 'C' && yy[2] != 'D')) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}
