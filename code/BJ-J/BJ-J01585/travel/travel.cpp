#include<bits/stdc++.h>
using namespace std;
int c,c_;
string s,s_;
bool icx()
{
    return c==c_;
}
bool iyp()
{
    return s[0]==s_[0]&&s[1]==s_[1];
}
bool itc()
{
    return s[2]<='C'&&s_[2]<='C'||s[2]>='D'&&s_[2]>='D';
}
bool ixl()
{
    return abs(s[2]-s_[2])==1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c_>>s_;
    if(icx()) cout<<1;
    else cout<<0;
    if(iyp()&&icx()) cout<<1;
    else cout<<0;
    if(iyp()&&icx()&&itc()) cout<<1;
    else cout<<0;
    if(iyp()&&icx()&&itc()&&ixl()) cout<<1;
    else cout<<0;
    return 0;
}
