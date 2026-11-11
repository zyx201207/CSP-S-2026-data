#include <bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;
bool chk() {
    if(a2[2] == 'D' && b2[2] == 'F') {
        return 1;
    }
    if(a2[2] == 'F' && b2[2] == 'D') {
        return 1;
    }
    if(a2[2] >= 'A' && a2[2] <= 'C' && b2[2] >= 'A' && b2[2] <= 'C') {
        return 1;
    }
    return 0;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 != b1) {
        cout << "0000";
        return 0;
    }
    else {
        cout << 1;
        if(a2[0] != b2[0] || a2[1] != b2[1]) {
            cout << "000";
            return 0;
        }
        else {
            cout << 1;
            if(!chk()) {
                cout << "00";
                return 0;
            }
            else {
                cout << 1;
                char tmp = a2[2]-1, tmp2=a2[2]+1;
                if(tmp == b2[2] || tmp2 == b2[2]) {
                    cout << 1;
                }
                else cout << 0;
            }
        }
    }
    return 0;
}