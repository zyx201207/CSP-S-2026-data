#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a = 0,b = 0,c = 0,d = 0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1[1] == c2[1] && c1[0] == c2[0]) a = 1;
    if (a == 1)
    {
        if(s1[1] == s2[1] && s1[0] == s2[0]) b = 1;
        if(b == 1)
        {
            if (s1[2] <= 'C' and s2[2] <= 'C') c = 1;
            else if (s1[2] > 'C' and s2[2] > 'C') c = 1;
            if (c == 1)
            {
                if(s1[2] - 'A' == s2[2] - 'A' - 1 or s1[2] - 'A' - 1 == s2[2] - 'A') d = 1;
            }
        }
    }
    cout << a << b << c << d;
    return 0;
}
