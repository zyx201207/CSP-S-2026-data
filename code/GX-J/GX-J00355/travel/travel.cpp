#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,ans,c,s;
    bool k;
    cin >> c1 >> c2>>s1>>s2;
    for(int i = 1;i <= c.size();i++)
    {
        if(c1 == c2)
        {
            k = 1;
            ans += char(k);
        }
        else
        {
            k = 0;
            ans += char(k);
        }
    }
    for(int i = 1;i <= s.size();i++)
    {
        if(s1[0] == s2[0] && s1[1] == s2[1] && s1[2] == s2[2])
        {
            k = 1;
            ans += char(k);
        }
        else
        {
            k = 0;
            ans += char(k);
        }
    }
    cout << ans;
    return 0;
}
