#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010],s[500010];
ll ans=0;
ll sol(ll x)
{
    ll l=1,r=x,ret=1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll cos=(a[x]*(x-mid+1))-(s[x]-s[mid-1]);
        if(cos<=m)
            ret=max(ret,x-mid+1);
        if(cos>m)
            l=mid+1;
        else
            r=mid-1;
    }
    return ret;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(ll i=1;i<=n;i++)
        ans=max(ans,sol(i));
    cout<<ans;
    return 0;
}
