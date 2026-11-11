#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],sum[500005],ans;

bool chk(int mid)
{
    for(int i=mid;i<=n;i++) if(a[i]*mid-(sum[i]-sum[i-mid])<=m) return true;
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(chk(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}