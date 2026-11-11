#include <bits/stdc++.h>
using namespace std;

bool same[4];

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        same[0] = true;
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            same[1] = true;
            if (s1[2] <= 67 && s2[2] <= 67 || s1[2] >= 68 && s2[2] >= 68)
            {
                same[2] = true;
                if (abs(s1[2] - s2[2]) == 1)
                {
                    same[3] = true;
                }
            }
        }
    }
    for (int i = 0;i <= 3;i++)
    {
        if (same[i])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    return 0;
}
