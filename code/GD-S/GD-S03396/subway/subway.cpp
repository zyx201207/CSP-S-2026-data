#include <bits/stdc++.h>
using namespace std;
vector <pair<int, long long>> box[500010];
//           id   time
long long c, n, m, d, q;
long long g[510][510];
long long w[500010];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= 500; i++)
		for (int j = 1; j <= 500; j++)
		{
			if (i != j) g[i][j] = 1e18;
		}
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			int a, t;
			scanf("%d %d", &a, &t);
			box[a].push_back(make_pair(i, t));
		}
	}
	for (int i = 1; i <= 500000; i++)
	{
		for (int j = 0; j < (int)box[i].size(); j++)
			for (int k = j + 1; k < (int)box[i].size(); k++)
			{
				int J = box[i][j].first, K = box[i][k].first;
				g[J][K] = min(g[J][K], box[i][j].second+box[i][k].second);
				g[K][J] = min(g[K][J], box[i][j].second+box[i][k].second);
			}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		long long ans = 1e18;
		for (int j = 0; j < (int)box[x].size(); j++)
			for (int k = 0; k < (int)box[y].size(); k++)
			{
				int J = box[x][j].first;
				int K = box[y][k].first;
				ans = min(ans, g[J][K] + box[x][j].second + box[y][k].second + w[x] + w[y]);
			}
		printf("%lld\n", ans);
	}
	return 0;
}
