#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500010];
ll sum[500010];
bool check(int x)
{
    ll minn=1e18;
    for(int i=x;i<=n;i++)
    {
        minn=min(minn,x*a[i]-(sum[i]-sum[i-x]));
    }
    return minn<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
