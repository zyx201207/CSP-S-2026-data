#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a1,a2,a3,a4;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    a1 = (c1 == c2);
    if (a1 && s1[0] == s2[0] && s1[1] == s2[1]) a2 = 1;
    else a2 = 0;
    if (a2 && ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'))) a3 = 1;
    else a3 = 0;
    if (a3 && ((s1[2] <= 'C' && s2[2] <= 'C' && abs(int(s1[2]) - int(s2[2])) == 1) || ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')))) a4 = 0;
    else a4 = 0;
    cout << a1 << a2 << a3 << a4;
    return 0;
}

