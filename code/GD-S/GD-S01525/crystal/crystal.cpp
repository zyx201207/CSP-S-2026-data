#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0,lst=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-lst+1)-sum[i]+sum[lst-1]>m)
		{
			lst++;
		}
		ans=max(ans,i-lst+1);
	}
	printf("%lld\n",ans);
	return 0;
}
