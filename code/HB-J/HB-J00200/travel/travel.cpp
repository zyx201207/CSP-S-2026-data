// Don't forget to open long long
#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if (a != c) {
        cout << "0000";
    }
    else {
        cout << 1;
        if (b[0] + b[1] == d[0] + d[1]) {
            cout << '1';
            if ((b[2] == 'D' && d[2] == 'E') || (b[2] == 'E' && d[2] == 'D')) {
                cout << "11";
            }
            else if ((b[2] <= 'C') && d[2] >= 'D') {
                cout << "00";
            }
            else {
                cout << '1';
                if ((b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A')) {
                    cout << '0';
                }
                else cout << '1';
            }
        }
        else cout << "000";
    }
    return 0;
}
