#include<bits/stdc++.h>
#define ll long long
#define sz (r-l+1)
using namespace std;
const int maxn=500005;
int n,ans;
ll m,a[maxn],q[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1; i<=n; ++i)
        scanf("%lld",&a[i]);
    for(int i=1; i<=n; ++i)
        a[i]=-a[i];
    sort(a+1,a+n+1);
    int l,r;
    ll sum=0;
    r=1;
    for(l=1; l<=n; ++l)
    {
        while(r<n && sum+a[r+1]-a[l]<=m)
        {
            sum+=a[r+1]-a[l];
            ++r;
        }
        ans=max(ans,sz);
        sum-=(a[l+1]-a[l])*(sz-1);
    }
    printf("%d\n",ans);
}
