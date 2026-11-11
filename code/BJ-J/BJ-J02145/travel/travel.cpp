#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool ans1, ans2, ans3, ans4;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2) ans1 = 1;

    if(ans1)
    {
        if(s1.size() == 2 && s2.size() == 2)
        {
            if(s1[0] == s2[0])
                ans2 = 1;
        }
        else if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            ans2 = 1;
        }
    }

    char zimu1 = s1[s1.size()-1], zimu2 = s2[s2.size()-1];
    if(ans1 && ans2 && ((zimu1 <= 'C' && zimu2 <= 'C') || (zimu1 >= 'D' && zimu2 >= 'D')))
        ans3 = 1;
    if(ans1 && ans2 && ans3 && abs(zimu1 - zimu2) == 1)
        ans4 = 1;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
