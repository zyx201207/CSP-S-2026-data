
#include <bits/stdc++.h>
using namespace std;

bool side(char c) {
    if(c == 'A' || c == 'B' || c == 'C') return 1;
    return 0;
}

int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 != c2) cout << "0000" << endl;
    else {
        cout << 1;
        //the same row?
        if(s1[1] != s2[1] || s1[0] != s2[0]) cout << "000" << endl;
        else {
            cout << 1;
            //the same side?
            if(side(s1[2]) != side(s2[2])) cout << "00" << endl;
            else {
                cout << 1;
                //AC or CA then cout << 0
                if(s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A') cout << 0 << endl;
                else cout << 1 << endl;
            }
        }
    }

    return 0;
}
