#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],pre[500005];
ll val(ll l,ll r)
{
    ll x=pre[r]-pre[l-1];
    return a[r]*(r-l+1)-x;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    int i=1,j=1;
    int ans=0;
    while(i<=n&&j<=n)
    {
        while(val(i,j+1)<=m&&j+1<=n)++j;
        ans=max(ans,j-i+1);
        ++i;
    }
    cout<<ans<<endl;
    return 0;
}