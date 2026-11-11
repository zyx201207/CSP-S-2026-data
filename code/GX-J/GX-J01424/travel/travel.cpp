#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,ans;
    cin>>c1>>s1>>c2>>s2;
    if(c1==s1)
    {
        ans+='1';
        if(c2[0]==s2[0]&&c2[1]==s2[1])
        {
            ans+='1';
            if(c2[2]=='C'&&s2[2]=='C')
            {
                ans+='1';
            }
            if(abs(c2[2]-s2[2])==1)
            {
                ans+='1';
            }
            else
            {
                ans+='0';
            }
            if(c2[2]=='D'&&s2[2]=='D'||c2[2]=='E'&&s2[2]=='E')
            {
                ans+="11";
            }
            else
            {
                ans+="00";
            }
        }
    }
    cout<<ans;
    return 0;
}
