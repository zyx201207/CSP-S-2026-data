#include <bits/stdc++.h>
using namespace std;
//#define int long long
signed main()
{
    //freopen("travel3.in","r",stdin);
    //freopen("travel3.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        printf("1");
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            printf("1");
            if(s1[2] == 'A' && s2[2] == 'B')
            {
                printf("11");
            }
            else if(s1[2] == 'A' && s2[2] == 'C')
            {
                printf("10");
            }
            else if(s1[2] == 'B' && s2[2] == 'A')
            {
                printf("11");
            }
            else if(s1[2] == 'B' && s2[2] == 'C')
            {
                printf("11");
            }
            else if(s1[2] == 'C' && s2[2] == 'A')
            {
                printf("10");
            }
            else if(s1[2] == 'C' && s2[2] == 'B')
            {
                printf("11");
            }
            else if(s1[2] == 'D' && s2[2] == 'F')
            {
                printf("11");
            }
            else
            {
                printf("00");
            }
        }
        else
        {
            printf("000");
        }
    }
    else
    {
        printf("0000");
    }
    return 0;
}
