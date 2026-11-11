#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int flag1,flag2,flag3,flag4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) flag1 = 1;
    if ((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1])) flag2 = 1;
    if ((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1]) && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))) flag3 = 1;
    if ((c1 == c2) && (s1[0] == s2[0]) && (s1[1] == s2[1]) && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && (abs(s1[2]-s2[2]) == 1)) flag4 = 1;
    cout << flag1 << flag2 << flag3 << flag4;
    return 0;
}