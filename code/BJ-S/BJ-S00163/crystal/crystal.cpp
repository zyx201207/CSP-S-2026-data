#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],sum,l,r,m,ans,mid,pre[500005];
bool check(ll x)
{
    for(ll i = x;i<=n;i++)
    {
        if(pre[i]-pre[i-x]+m>=x*a[i])return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i = 1;i<=n;i++)
    {
        pre[i] = pre[i-1]+a[i];
    }
    l = 1,r = n;
    while(l<=r)
    {
        mid = l+r>>1;
        if(check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout<<ans;
}