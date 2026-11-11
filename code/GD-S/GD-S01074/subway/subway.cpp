#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,M = 5e5 + 5,D = 25;
int ID,n,m,d,q,w[M],a[M][D],t[M][D],cnts[M],dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&ID,&n,&m,&d,&q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dis[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= m; i++) scanf("%lld",&w[i]);
	for (int i = 1,k; i <= n; i++)
	{
		scanf("%lld",&k);
		dis[i][i] = 0;
		for (int j = 1,x,y; j <= k; j++)
		{
			scanf("%lld%lld",&x,&y);
			a[x][++cnts[x]] = i;
			t[x][cnts[x]] = y;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < cnts[i]; j++)
		{
			for (int k = j + 1; k <= cnts[i]; k++)
			{
				int jj = a[i][j],kk = a[i][k];
				dis[jj][kk] = min(dis[jj][kk],t[i][j] + t[i][k]);
				dis[kk][jj] = dis[jj][kk];
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
	while (q--)
	{
		int x,y,ans = 1e18;
		scanf("%lld%lld",&x,&y);
		for (int i = 1; i <= cnts[x]; i++)
		{
			for (int j = 1; j <= cnts[y]; j++)
			{
				ans = min(ans,dis[a[x][i]][a[y][j]] + t[x][i] + t[y][j] + w[x] + w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
