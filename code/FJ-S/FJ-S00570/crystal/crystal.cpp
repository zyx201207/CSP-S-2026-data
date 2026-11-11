#include<bits/stdc++.h>
#define endl '\n'
#define N 500006
using namespace std;
using i64=long long;
int n,ans; i64 m,a[N],sum[N];
main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  scanf("%d%lld",&n,&m);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
  for(int i=1;i<=n;i++)
  {
    int l=1,r=i,res=i;
    while(l<=r)
    {
      int mid=l+r>>1;
      i64 targ=1ll*(i-mid+1)*a[i];
      if(targ-(sum[i]-sum[mid-1])<=m)res=mid,r=mid-1;
      else l=mid+1;
    }
    ans=max(ans,i-res+1);
  }
  printf("%d\n",ans);
  return 0;
}
