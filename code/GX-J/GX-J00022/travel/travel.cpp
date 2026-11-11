#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> c2 >> s1 >> s2;
    if(c1 == s1)cout << 1;
    else cout << 0;
    if(c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1])cout << 1;
    else cout << 0;
    if(c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1] && (('A' <= c2[2] && c2[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) || ((c2[2] == 'D' || c2[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')))cout << 1;
    else cout << 0;
    if(c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1] && (c2[2] == 'D' || s2[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))cout << 1;
    else if(c1 == s1 && c2[0] == s2[0] && c2[1] == s2[1] && ('A' <= c2[2] && c2[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C') && abs(s2[2] - c2[2]) == 1)cout << 1;
    else cout << 0;
    return 0;
}
