#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], g[505][505], a[500005], t[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(g, 0x3f, sizeof g);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]), g[i][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
			scanf("%d%d", &a[j], &t[j]);
		for (int j = 2; j <= k; j++)
			for (int l = 1; l < j; l++)
				g[a[l]][a[j]] = g[a[j]][a[l]] = min(g[a[j]][a[l]], t[j] + t[l]);
	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			printf("%d ", g[i][j]);
//		printf("\n");
//	}
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", g[x][y] + w[x] + w[y]);
	}
	return 0;
}
