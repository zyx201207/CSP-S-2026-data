#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1])
    {
        ans="1000";
        if(s1[1]!=s2[1])
        {
            cout<<"1000";
            return 0;
        }
        else
        {
            ans="1100";
        }
        if((s1[2]=='A'&&(s2[2]=='B' || s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A' || s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='B' || s2[2]=='A'))||(s1[2]=='D'&&s2[2]=='F')||(s1[1]=='F'&&(s2[1]=='D')))
        {
            ans="1110";
            if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))
            {
                ans="1111";
            }
        }
    }
    else if(c1!=c2 || c1=="01" || c2=="01" || c1=="16" || c2=="16")
    {
        ans="0000";
    }
    cout<<ans;
    return 0;
}
