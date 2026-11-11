#include<bits/stdc++.h>
using namespace std;
#define int long long
bool func(char x,char y)
{
    if (x=='D'&&y=='F'||x=='F'&&y=='D')
        return true;
    if (x=='C'&&y=='D'||x=='D'&&y=='C')
        return false;
    return abs(x-y)==1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2)
        cout<<1;
    else
        cout<<0;
    string s1a=s1.substr(0,2),s2a=s2.substr(0,2);
    char s1b=s1[2],s2b=s2[2];
    if (c1==c2&&s1a==s2a)
        cout<<1;
    else
        cout<<0;
    if (c1==c2&&s1a==s2a&&((s1b<'D'&&s2b<'D')||(s1b>='D'&&s2b>='D')))
        cout<<1;
    else
        cout<<0;
    if (c1==c2&&s1a==s2a&&func(s1b,s2b))
        cout<<1;
    else
        cout<<0;
}
