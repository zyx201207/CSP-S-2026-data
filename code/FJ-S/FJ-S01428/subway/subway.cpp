#include<bits/stdc++.h>
#define N 510
#define M 500010
#define D 25
#define LL long long
#define INF 50000000000000000
using namespace std;

int _, n, m, d, q;
int  cnt[M], lne[M][D];

LL lele[M], fd[N][N], wt[M][D];

int read()
{
	int res = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while('0' <= ch && ch <= '9') 
	{
		res = res * 10 + ch - '0';
		ch = getchar();
	}
	return res;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
//	scanf("%d%d%d%d%d", &_, &n, &m, &d, &q);
//	LL aaa =clock();
	_ = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++)
	{
//		scanf("%lld", &lele[i]);
		lele[i] = read();
	}
	for(int i = 1; i <= n; i++)
	{
		int kk, aa, tt;
//		scanf("%d", &kk);
		kk = read();
		for(int j = 1; j <= kk; j++)
		{
//			scanf("%d%d", &aa, &tt);
			aa = read(),
			cnt[aa]++,
			lne[aa][cnt[aa]] = i,
			wt[aa][cnt[aa]] = read();
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <=n ; j++)
		{
			fd[i][j] = fd[j][i] = INF;
		}
	}
//		cout<<clock()-aaa<<'\n';
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= cnt[i]; j++)
		{
			for(int k = j + 1; k <= cnt[i]; k++)
			{
				fd[lne[i][j]][lne[i][k]] = fd[lne[i][k]][lne[i][j]] = 
				min(fd[lne[i][j]][lne[i][k]], wt[i][j] + wt[i][k]);
			}
		}
	}
	
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				fd[i][j] = min(fd[i][j], fd[i][k] + fd[k][j]);
			}
		}
	}

	
	int xr, yr;
	LL ans;
	while(q--)
	{
		ans = INF;
//		scanf("%d%d", &xr, &yr);
		xr = read(), yr = read();
		for(int i = 1; i <= cnt[xr]; i++)
		{
			for(int j = 1; j <= cnt[yr]; j++)
			{
				if(fd[lne[xr][i]][lne[yr][j]] < INF)
				{
					ans = min(ans, (wt[xr][i] + wt[yr][j] + fd[lne[xr][i]][lne[yr][j]]));
				}
			}
		}
		ans += lele[xr] + lele[yr];		
		printf("%lld\n", ans);
	}
	return 0;
}