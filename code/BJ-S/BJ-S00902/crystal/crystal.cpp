#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],sa[500010],m;
bool chk(int x)
{
    long long cnt=1e18;
    for(int i=x;i<=n;i++)
    {
        long long sum=1ll*a[i]*x-sa[i]+sa[i-x];
        cnt=min(cnt,sum);
    }
    return cnt<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sa[i]=sa[i-1]+a[i];
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(chk(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
