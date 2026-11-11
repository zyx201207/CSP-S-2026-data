#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int sum[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n;
        int ans=i;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        //cout<<ans<<" ";
        maxx=max(maxx,i-ans+1);
    }
    cout<<maxx;
    return 0;
}
