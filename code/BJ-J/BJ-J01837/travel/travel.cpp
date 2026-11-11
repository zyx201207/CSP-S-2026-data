#include<bits/stdc++.h>
using namespace std;
map<char, int> mp;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    mp['A'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['D'] = 4;
    mp['E'] = 5;
    if(c1 != c2) {
        cout << "0000" << endl;
    } else {
        string a = s1.substr(0, 2);
        string b = s2.substr(0, 2);
        if(a != b) {
            cout << "1000" << endl;
        } else {
            int c = mp[s1[2]];
            int d = mp[s2[2]];
            if(c > d) swap(c, d);
            if(c >= 1 && c <= 3 && d >= 1 && d <= 3) {
                if(d - c == 1) cout << "1111" << endl;
                else cout << "1110" << endl;
            } else if(c == 4 && d == 5) {
                cout << "1111" << endl;
            } else {
                cout << "1100" << endl;
            }
        }
    }
    return 0;
}