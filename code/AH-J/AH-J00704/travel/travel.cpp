#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool check2 ()
{
    if (s1[2]>s2[2])
    {
        if (s1[2]-s2[2] == 1 && s1[2] != 'D') return 1;
        else return 0;
    }
    else
    {
        if (s2[2]-s1[2] == 1 && s2[2] != 'D') return 1;
        else return 0;
    }
}
bool check1 ()
{
    if (s1[2] > s2[2])
    {
        if (s1[2] >= 'D' && s2[2] < 'D') return 0;
        else return 1;
    }
    else
    {
        if (s2[2] >= 'D' && s1[2] < 'D') return 0;
        else return 1;
    }
}
int main ()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else cout << 0;
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else cout << 0;
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check1 ()) cout << 1;
    else cout << 0;
    if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && check2 () && check1 ()) cout << 1;
    else cout << 0;
    return 0;
}
