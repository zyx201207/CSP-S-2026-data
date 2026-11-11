#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005];
string s[200005];
bool cmp(string w,string e)
{
    return w>e;
}
string f1(ll x)
{
    string s1;
    while(x)
    {
        if(x%2==0) s1="0"+s1;
        else s1="1"+s1;
        x/=2;
    }
    while(s1.size()<30)
        s1="0"+s1;
    return s1;
}
ll f2(string x)
{
    ll t=1,y=0;
    for(ll i=x.size()-1;i>=0;i--)
    {
        if(x[i]=='1') y+=t;
        t*=2;
    }
    return y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++)
        s[i]=f1(a[i]);
    for(ll i=0;i<=30;i++)
    {
        ll t=0;
        for(ll j=1;j<=n;j++)
            if(s[j][i]=='1') t++;
        if(t==m)
        {
            string c="1111111111111111111111111111111";
            ll k=f2(c);
            for(ll j=1;j<=n;j++)
                if(s[j][i]=='1') k=k&f2(s[j]);
            cout<<k;
            return 0;
        }
        if(t>m)
        {
            for(ll j=1;j<=n;j++)
                if(s[j][i]=='0')
                {
                    for(ll h=0;h<=30;h++)
                        s[j][h]='0';
                    a[j]=-1;
                }
        }
    }
    sort(s+1,s+n+1,cmp);
    string c="1111111111111111111111111111111";
    ll k=f2(c);
    for(ll i=1;i<=m;i++)
        k=k&f2(s[i]);
    cout<<k;
    return 0;
}
