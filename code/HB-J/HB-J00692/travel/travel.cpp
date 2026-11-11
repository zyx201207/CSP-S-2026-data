#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool s1l,s2l;
int main()
{
    freopen("travele.in","r",stdin);
    freopen("travele.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') s1l = 1;
    if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') s2l = 1;
    if(s1[2] == 'D') s1[2] = 'E';
    if(s2[2] == 'D') s2[2] = 'E';
    if(c1 == c2 && s1.substr(0,2) == s2.substr(0,2) && ((int) (s1[2] - s2[2]) == 1 || (int) (s1[2] - s2[2]) == -1)) cout << 1111;
    else if(c1 == c2 && s1.substr(0,2) == s2.substr(0,2) && s1l == s2l) cout << 1110;
    else if(c1 == c2 && s1.substr(0,2) == s2.substr(0,2)) cout << 1100;
    else if(c1 == c2) cout << 1000;
    else cout << "0000";
    return 0;
}
