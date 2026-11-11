#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int sum[N],ans;

int calc(int k)
{
    int l=1,r=k;
    while (l<r)
    {   
        int mid=(l+r)>>1;
        if ((k-mid+1)*a[k]-sum[k]+sum[mid-1]<=m) r=mid;
        else l=mid+1;
    }
    return l;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++) ans=max(ans,i-calc(i)+1);
    cout<<ans<<"\n"; return 0;
}
//mj