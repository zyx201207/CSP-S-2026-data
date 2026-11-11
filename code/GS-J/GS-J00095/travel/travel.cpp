#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans="";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) ans+="1";
    else ans+="0";
    bool x=0;
    for(int i=0;i<2;i++)
    {
        if(s1[i]!=s2[i]) x=1;
    }
    if(x==0&&ans[0]=='1') ans+="1";
    else ans+="0";
    int a,b;
    a=(int)s1[2]-65;
    b=(int)s2[2]-65;
    if((a<=2&&b<=2||a>=3&&b>=3)&&ans[1]=='1') ans+="1";
    else ans+="0";
    if(abs(a-b)==1&&ans[2]=='1') ans+="1";
    else ans+="0";
    cout<<ans;
    return 0;
}
