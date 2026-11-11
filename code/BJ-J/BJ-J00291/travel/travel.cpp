#include <bits/stdc++.h>
using namespace std;

string x, y, xx, yy;

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> x >> y >> xx >> yy;
    string ans = "";
    if (x == xx) {
        ans += '1';
    }
    else {
        cout << "0000\n";
        return 0;
    }
    if (y[0] == yy[0] && y[1] == yy[1]) {
        ans += '1';
    }
    else {
        cout << "1000\n";
        return 0;
    }
    if ((y[2] <= 'C' && yy[2] <= 'C') || (y[2] >= 'D' && yy[2] >= 'D')) {
        ans += '1';
    }
    else {
        cout << "1100\n";
        return 0;
    }
    if (abs(y[2] - yy[2]) == 1) {
        cout << "1111\n";
    }
    else {
        cout  << "1110\n";
    }
    return 0;
}