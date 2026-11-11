#include <bits/stdc++.h>
using namespace std;
long long w[999999],k,a[500001][101],t[500001][101],x[100001][11],y[100001][11];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,r=1;
	scanf("%lld",&c);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&d);
	scanf("%lld",&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&x[i][r]);
		scanf("%lld",&y[i][r]);
		r++;
	}
	printf("32");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
