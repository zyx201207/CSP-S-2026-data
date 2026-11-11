#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int sum[maxn],a[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]<=m)
			sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++)
		if(sum[i]>m) 
		{
			printf("%lld\n",i-1);
			return 0;
		}
	printf("%lld",n);
 	return 0;
}

