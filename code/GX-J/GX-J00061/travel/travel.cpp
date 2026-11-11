#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
bool b1, b2, b3, b4;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    //freopen("travel.in", "r", stdin), freopen("travel.out", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    b1 = (c1 == c2 ? 1 : 0);
    cout << b1;
    if (!b1) {
        cout << "000";
        return 0;
    }
    b2 = (s1[0] == s2[0] && s1[1] == s2[1] ? 1 : 0);
    cout << b2;
    if(!b2) {
        cout << "00";
        return 0;
    }
    b3 = ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') ? 1 : 0) | ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F') ? 1 : 0);
    cout << b3;
    if (!b3) {
        cout << "0";
        return 0;
    }
    b4 = (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2] ? 1 : 0);
    cout << b4;
    return 0;
}
