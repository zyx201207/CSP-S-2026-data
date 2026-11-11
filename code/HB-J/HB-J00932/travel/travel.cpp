#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool is1 = false,is2 = false,is3 = false;
    if (c1 == c2)
    {
        cout << 1;
        is1 = true;
    }
    else
    {
        cout << 0;
    }
    if ((s1[1] == s2[1]) && is1)
    {
        cout << 1;
        is2 = true;
    }
    else
    {
        cout << 0;
    }
    if (((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && is2)
    {
        cout << 1;
        is3 = true;
    }
    else
    {
        cout << 0;
    }
    if (((s1[2] - s2[2] == 1  && s1[2] != 'D') || (s2[2] - s1[2] == 1 && s2[2] != 'D')) && is3)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
