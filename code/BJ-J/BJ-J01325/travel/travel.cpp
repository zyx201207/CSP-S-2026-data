#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    string ans="";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans+='1';
    }
    else
    {
        ans+="0000";
        cout<<ans;
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        ans+='1';
    }
    else
    {
        ans+="000";
        cout<<ans;
        return 0;
    }

    if( ('A'<=s1[2]&&s1[2]<='C') && ('A'<=s2[2]&&s2[2]<='C') )
    {
        ans+='1';
    }
    else if( (s1[2]=='D'||s1[2]=='F') && (s2[2]=='D'||s2[2]=='F') )
    {
        ans+="11";
        cout<<ans;
        return 0;
    }
    else
    {
        ans+="00";
        cout<<ans;
        return 0;
    }
    //A-C
    int x=abs(s1[2]-s2[2]);
    if(x==1)
    {
        ans+='1';
    }
    else
    {
        ans+='0';
    }
    cout<<ans;
    return 0;
}