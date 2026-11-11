#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],l,r,mid,sum[N],maxn;
bool cmp(ll a,ll b)
{
    return a<b;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++)
    {
        l=0,r=i+1;
        while(l<=r)
        {
            mid=l+(r-l)/2ll;
            if ((1ll*i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m)
                r=mid-1;
            else
                l=mid+1;
        }
        maxn=max(maxn,i-l+1);
    }
    printf("%lld\n",maxn);
    return 0;
}