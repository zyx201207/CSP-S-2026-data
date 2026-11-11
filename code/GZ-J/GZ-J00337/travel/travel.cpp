//GZ-J00337黄寅轩观山湖区华润中学
#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2, sa, sb;
char jg[5] = {'0', '0', '0', '0', '0'};

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        jg[1] = '1';
    }
    else
    {
        for(int i = 1; i <= 4; i++)
        {
            cout << jg[i];
        }
        return 0;
    }
    for (int i = 0; i <= 1; i++)
    {
        sa[i] = s1[i];
        sb[i] = s2[i];
    }
    if (sa == sb)
    {
        jg[2] = '1';
    }
    else
    {
        for(int i = 1; i <= 4; i++)
        {
            cout << jg[i];
        }
        return 0;
    }
    if (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C')
    {
        jg[3] = '1';
    }
    else if (s1[2] == 'D' && s2[2] == 'F' && s1[2] == 'F' && s2[2] == 'D' )
    {
        jg[3] = '1';
    }
    else
    {
        for(int i = 1; i <= 4; i++)
        {
            cout << jg[i];
        }
        return 0;
    }
    if (s1[2] == 'A' && s2[2] != 'C' || s1[2] == 'B' && s2[2] == 'C' )
    {
        jg[4] = '1';
    }
    else if ( s1[2] == 'D' && s2[2] == 'F' ||  s1[2] == 'F' && s2[2] == 'D')
    {
        jg[4] = '1';
    }
    for(int i = 1; i <= 4; i++)
    {
        cout << jg[i];
    }
    return 0;
return 0;
}
