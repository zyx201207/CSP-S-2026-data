#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,a[500005],dp[1005][1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	long long t,x,y,s,e;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		for(int j=1;j<=t;j++)
			scanf("%lld%lld",&x,&y);
	}
	while(p--)
	{
		scanf("%lld%lld",&s,&e);
		printf("%lld/n",s*e);
	}
	return 0;
}
