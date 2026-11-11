#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    string ans="";
    cin>>c1>>c2>>s1>>s2;
    if(c1!=s1) ans+='0';
    else ans+='1';
    if(ans[0]=='1')
    {
        if(s2[0]!=c2[0] || s2[1]!=c2[1]) ans+='0';
        else ans+='1';
    }
    else ans+='0';
    if(ans[1]=='1')
    {
        if(s2[2]==c2[2]) ans+='0';
        else
        {
            if((s2[2]>='A' && s2[2]<='C' && c2[2]>='A' && c2[2]<='C') || (s2[2]>='D' && s2[2]<='F' && c2[2]>='D' && c2[2]<='F')) ans+='1';
            else ans+='0';
        }
    }
    else ans+='0';
   if(ans[2]=='1')
   {
        if(s2[2]==char(c2[2]+1)) ans+='1';
        else ans+='0';
   }
   else ans+='0';
   cout<<ans;
    return 0;
}
