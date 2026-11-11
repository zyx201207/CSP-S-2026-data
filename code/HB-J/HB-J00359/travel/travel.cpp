#include <bits/stdc++.h>
using namespace std;
map <char, int> mp;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    mp['A'] = 1;
    mp['B'] = 1;
    mp['C'] = 1;
    mp['D'] = 2;
    mp['E'] = 2;
    string s1, s2;
    int c1, c2;
    cin >> c1 >> s1 >> c2 >> s2;
    cout << c1 << ' ' << s1 << ' ' << c2 << ' ' << s2 << '\n';
    if (s1[2] == 'F') s1[2] = 'E';
    if (s2[2] == 'F') s2[2] = 'E';
    bool b1 = ( c1 == c2 );
    bool b2 = ( b1 && s1[0] == s2[0] && s1[1] == s2[1] );
    bool b3 = ( b2 && ( mp[s1[2]] == mp[s2[2]] ) );
    bool b4 = ( b3 && abs(s1[2] - s2[2]) == 1 );
    cout << b1 << b2 << b3 << b4;
    return 0;
}
