#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
     cin>>c1>>s1>>c2>>s2;
     if(c1[1]!=c2[1])
     {
         ans+='0';
         ans+='0';
         ans+='0';
         ans+='0';
         cout<<ans;
         return 0;
     }
     else
     {
         ans+='1';
     }
     if(s1[0]==s2[0]&&s1[1]==s2[1])
     {
         ans+='1';
     }
     else
     {
         ans+='0';
         ans+='0';
         ans+='0';
         cout<<ans;
         return 0;
     }
     if(s1[2]=='C'&&s2[2]=='D')
     {
         ans+='0';
         ans+='0';
         cout<<ans;
         return 0;
     }
     else if(s1[2]=='D'&&s2[2]=='C')
     {
         ans+='0';
         ans+='0';
         cout<<ans;
         return 0;
     }
     else if(s1[2]-s2[2]<=2)
     {
         ans+='1';
     }
     int a=s1[2]-s2[2];
     if(a==1)
     {
         ans+='1';
     }
     if(a==-1)
     {
         ans+='1';
     }
     for(int i=1;i<=4;i++)
     {
         if(ans.size()<4)
         {
            ans+='0';
         }
     }
     cout<<ans;
     return 0;
}
