#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,s1,s2;
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2) cout<<1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        if(s1[2]<='C'&&s2[2]<='C') cout<<1;
        else if(s1[2]>='D'&&s2[2]>='D') cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        if(s1[2]<='C'&&s2[2]<='C'&&abs(s1[2]-s2[2])==1) cout<<1;
        else if(s1[2]>='D'&&s2[2]>='D') cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
