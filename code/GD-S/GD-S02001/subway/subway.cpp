#include <bits/stdc++.h>
using namespace std;

int ccc, n, m, dd, q, k[505], qx, qy, jj[500005], dx;

long long w[500005], ans = 1e18, d[505][505], bn[505][505];

map<int, int> ji1[500005], ji2[500005], a[505], t[505];

void dfs(int xx)
{
	for (int l = 1; l <= n; l++)
	{
		if (bn[xx][l] == -1)
		{
			continue; 
		}
		if (d[dx][l] > d[dx][xx] + bn[xx][l])
		{
			d[dx][l] = d[dx][xx] + bn[xx][l];
			dfs(l);
		}
	}
	return;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &ccc, &n, &m, &dd, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
		{
			scanf("%d%d", &a[i][j], &t[i][j]);
			jj[a[i][j]]++;
			ji1[a[i][j]][jj[a[i][j]]] = i;
			ji2[a[i][j]][jj[a[i][j]]] = t[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bn[i][j] = d[i][j] = 1e18;
		}
		bn[i][i] = d[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= jj[i]; j++)
		{
			for (int l = j + 1; l <= jj[i]; l++)
			{
				bn[ji1[i][j]][ji1[i][l]] = min(bn[ji1[i][j]][ji1[i][l]], (long long)(ji2[i][j] + ji2[i][l]));
				bn[ji1[i][l]][ji1[i][j]] = bn[ji1[i][j]][ji1[i][l]];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (bn[i][j] == 1e18)
			{
				bn[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dx = i;
		dfs(i);
	}
	while (q--)
	{
		scanf("%d%d", &qx, &qy);
		ans = 1e18;
		for (int i = 1; i <= jj[qx]; i++)
		{
			for (int j = 1; j <= jj[qy]; j++)
			{
				ans = min(ans, (long long)d[ji1[qx][i]][ji1[qy][j]] + w[qx] + w[qy] + ji2[qx][i] + ji2[qy][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
