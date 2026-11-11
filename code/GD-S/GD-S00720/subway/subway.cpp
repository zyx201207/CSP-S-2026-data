#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 505, M = 5e5 + 5;
const LL INF = 1e18;

int c;
int n, m, d, q;

LL w[M];
vector<int> a[N];
vector<pair<int, LL> > v[M];

LL dis[N][N];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ ) cin >> w[i];
	for (int i = 1; i <= n; i ++ )
	{
		int k; cin >> k;
		while (k -- )
		{
			int u; LL t; cin >> u >> t;
			a[i].push_back(u);
			v[u].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			if (i != j)
				dis[i][j] = INF;
	for (int u = 1; u <= m; u ++ )
		for (int i = 0; i < (int)v[u].size(); i ++ )
			for (int j = 0; j < (int)v[u].size(); j ++ )
				if (i != j)
					dis[v[u][i].first][v[u][j].first] = min(dis[v[u][i].first][v[u][j].first], v[u][i].second + v[u][j].second);
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	while (q -- )
	{
		int s, t; cin >> s >> t;
		
		LL res = INF;
		for (auto i : v[s])
			for (auto j : v[t])
				res = min(res, w[s] + w[t] + i.second + j.second + dis[i.first][j.first]);
		
		cout << res << '\n';
	}

	return 0;
}

