#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m,a[500010],sum[500010];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if((ll)a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
            {
                ans=max(ans,i-mid+1);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
