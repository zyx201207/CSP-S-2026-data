#include<bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4 + 5, maxm = 5 * 1e2 + 5;
int c, n, m, d, q, ans, W[maxn], k[maxm], aa[maxm][maxn], t[maxm][maxn], f[maxm][maxm];
struct Node
{
	int id, rnk, val;
};
vector<Node> G[maxn];
void Floyd()
{
	for (int k = 1; k <= n; ++ k)
	{
		for (int i = 1; i <= n; ++ i)
		{
			for (int j = 1; j <= n; ++ j)
			{
				if (f[i][k] == f[maxm - 1][maxm - 1] || f[k][j] == f[maxm - 1][maxm - 1])
				{
					continue;
				}
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i)
	{
		cin >> W[i];
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++ i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++ j)
		{
			cin >> aa[i][j] >> t[i][j];
			if (c >= 16 && c <= 19)
			{
				for (auto v : G[aa[i][j]])
				{
					//cout << v.id << " " << i << " " << f[i][v.id] << '\n';
					f[v.id][i] = f[i][v.id] = min(f[i][v.id], t[i][j] * 2);
				}
			}
			G[aa[i][j]].push_back({i, j, t[i][j]});
		}
	}
	for (int i = 1; i <= n; ++ i)
	{
		f[i][i] = 0;
	}
	if (c < 16 || c > 19)
	{
		for (int i = 1; i <= m; ++ i)
		{
			for (int j = 0; j < (int)G[i].size(); ++ j)
			{
				for (int k = j + 1; k < (int)G[i].size(); ++ k)
				{
					f[G[i][j].id][G[i][k].id] = f[G[i][k].id][G[i][j].id] = min(f[G[i][j].id][G[i][k].id], G[i][j].val + G[i][k].val);
				}
			}
		}
	}
	Floyd();
	while (q --)
	{
		int x, y, ans = INT_MAX;
		cin >> x >> y;
		for (auto v : G[x])
		{
			for(auto w : G[y])
			{
				ans = min(ans, W[x] + W[y] + t[v.id][v.rnk] + t[w.id][w.rnk] + f[v.id][w.id]);
			}
		}
		cout << ans << endl;
	}
	/*
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
	*/
	return 0;
}
