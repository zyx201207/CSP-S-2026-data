#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+5,inf=1e18;
int n,m,a[N];
int s[N];
int ans=1ll;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,res=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m)
                res=i-mid+1,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,res);
    }
    printf("%lld\n",ans);
    return 0;
}