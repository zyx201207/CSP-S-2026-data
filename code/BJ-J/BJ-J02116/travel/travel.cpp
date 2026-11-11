#include <bits/stdc++.h>
using namespace std;
string sx, sy;
int main (){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b;
    cin >> a >> sx >> b >> sy;
    if (a == b) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    if (sx[0] == sy[0] && sx[1] == sy[1]) cout << 1;
    else {
        cout << "000";
        return 0;
    }
    if ((sx[2] > 'C' && sy[2] > 'C') || (sx[2] <= 'C' && sy[2] <= 'C')) cout << 1;
    else {
        cout << "00";
        return 0;
    }
    if (((sx[2] - sy[2]) == 1) || ((sy[2] - sx[2]) == 1)) cout << 1;
    else cout << 0;

    return 0;
}
