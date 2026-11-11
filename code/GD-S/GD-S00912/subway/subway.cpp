#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long f;
	long long n;
	long long ne;
 }zhan[500005];
long long huan[500005][505];
long long chu[500005];
long long c,n,m,d,q;
long long ans = 1e16;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(long long i = 1; i<=m; i++)cin >> chu[i];
	for(long long i = 1; i<=n; i++)
	{
		long long k;
		scanf("%lld",&k);
		for(int j = 1; j<=k; j++)
		{
			int a,t;
			scanf("%lld %lld",&a,&k);
			if(j > 1)
			{
				zhan[a].n = a;
				zhan[j-1].ne = a;
				zhan[a].f = zhan[j-1].n;
			}
			else
			{
				zhan[a].f = -1;
				zhan[a].n = a;
			}
			huan[j][i] = t;
		}
	}
	for(int i = 1; i<=q; i++)
	{
		int xr,yr;
		cin >> xr >> yr;
		bfs(xr,1);
		cout << ans << endl;
	}
}
