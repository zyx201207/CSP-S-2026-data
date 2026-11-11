#include<bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

map<char, int>mp;

int main() {
    mp['A'] = 1, mp['B'] = 2, mp['C'] = 3, mp['D'] = 5, mp['F'] = 6;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2) {
        cout << "0000";
        return 0;
    }
    if(s1.substr(0, 2) != s2.substr(0, 2)) {
        cout << "1000";
        return 0;
    }
    int side1 = s1[2] > 'C', side2 = s2[2] > 'C';
    if(side1 != side2) {
        cout << "1100";
        return 0;
    }
    int pos1 = mp[s1[2]], pos2 = mp[s2[2]];
    if(abs(pos1 - pos2) != 1) {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}
