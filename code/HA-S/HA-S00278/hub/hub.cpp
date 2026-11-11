#include <bits/stdc++.h>
using namespace std;
long long u[1000001],v[1000001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	scanf("%lld",&c);
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		int n,k;
		scanf("%lld",&n);
		scanf("%lld",&k);
		for(int j=1;j<=n-1;j++)
		{
			scanf("%lld",&u[j]);
			scanf("%lld",&v[j]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
