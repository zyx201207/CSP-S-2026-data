#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c1,c2;
string s1,s2;
char k1,k2;
bool pan()
{
    if(k1=='A'&&k2=='B') return 1;
    if(k1=='B'&&k2=='A') return 1;
    if(k1=='B'&&k2=='C') return 1;
    if(k1=='C'&&k2=='B') return 1;
    if(k1=='A'&&k2=='C') return 1;
    if(k1=='C'&&k2=='A') return 1;

    if(k1=='D'&&k2=='F') return 1;
    if(k1=='F'&&k2=='D') return 1;

    return 0;
}
bool pan2()
{
    if(k1=='A'&&k2=='B') return 1;
    if(k1=='B'&&k2=='A') return 1;
    if(k1=='B'&&k2=='C') return 1;
    if(k1=='C'&&k2=='B') return 1;

    if(k1=='D'&&k2=='F') return 1;
    if(k1=='F'&&k2=='D') return 1;

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;

    ll a1=0,a2=0;
    ll x,y;
    x=s1[0]-48;
    y=s1[1]-48;
    a1=x*10+y;//
    x=s2[0]-48;
    y=s2[1]-48;
    a2=x*10+y;
    if(a1==a2 && c1==c2) cout<<1;
    else cout<<0;

    k1=s1[2];
    k2=s2[2];
    if(pan() && a1==a2 && c1==c2) cout<<1;
    else cout<<0;

    if(pan2() && a1==a2 && c1==c2) cout<<1;
    else cout<<0;
    return 0;
}
