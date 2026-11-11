#include <bits/std++.h>
using namespace std;
string c1, s1, c2, s2;
int main{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    for(int i = 0; i < 3; i++) cin >> c1[i] >> s1[i] >> c2[i] >> s2[i];
    if(c1 == c2) cout << 1;
    else cout << 0;
    if(s1[1] == s2[1]) cout << 1;
    else cout << 0;
    if(s1[1] == s2[1] && char(s1[2]) == char(s2[2] - 1 && s2[2] + 1)) cout << 1;
    else cout << 0;
    if(char(s1[2]) == char(s2[2] - 1 && s2[2] + 1)) cout << 1;
    else cout << 0;
return 0
}
