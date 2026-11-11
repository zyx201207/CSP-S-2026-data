#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int f[N],sum[N],ans;

signed main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n,&m);
	for(int i=1; i<=n; i++)
	scanf("%lld", &a[i]),sum[i]=sum[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
	sum[i]=sum[i-1]+a[i];
	for(int i=1; i<=n; i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int j=((l+r)>>1);
//			printf("%d %d %d\n", i, l, r);
			if((i-j+1)*a[i]-(sum[i]-sum[j-1])<=m) 
			r=j;
			else
			l=j+1;
		}
		ans=max(ans, i-l+1);
	}
	printf("%lld", ans);
	return 0;
} 
