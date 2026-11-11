#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 2e5+5;
string c1, s1, c2, s2;
char m[128];

int main(){
    ios::sync_with_stdio(false);
    file(travel);

    m['A'] = 'B';
    m['B'] = 'C';
    m['D'] = 'F';

    cin >> c1 >> s1 >> c2 >> s2;
    if(s1 > s2) swap(s1, s2);
    if(c1 != c2) cout << "0000";
    else if(s1[0] != s2[0] || s1[1] != s2[1]) cout << "1000";
    else if((s1[2] < 'D') != (s2[2] < 'D')) cout << "1100";
    else if(m[s1[2]] != s2[2]) cout << "1110";
    else cout << "1111";

    return 0;
}
