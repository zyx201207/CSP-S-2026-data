#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long ans,l,r,mid,sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++)
    {
        l=1,r=i;
        while (l<r)
        {
            int mid=(l+r)/2;
            if (sum[i]-sum[mid-1]+m>=(i-mid+1)*a[i]) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
        // cout << i-l+1 << endl;
    }
    cout << ans << endl;
    return 0;
}