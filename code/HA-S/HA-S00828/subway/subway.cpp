#include <bits/stdc++.h>

using namespace std;

#define int long long

ifstream fin("subway.in");
ofstream fout("subway.out");
#define cin fin
#define cout fout

const int N = 510, M = 5e5 + 10, inf = 1e18;

int c, n, m, d, q;

int dis[N][N], w[M];
vector<array<int, 2>> all[M];

void chkmin(int &x, int y)
{
	x = min(x, y);
}

signed main()
{
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		int k; cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int a, t; cin >> a >> t;
			all[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < all[i].size(); j++)
			for (int k = j + 1; k < all[i].size(); k++)
			{
				int u = all[i][j][0], uw = all[i][j][1], v = all[i][k][0], vw = all[i][k][1];
				chkmin(dis[u][v], uw + vw);
			}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			chkmin(dis[i][j], dis[j][i]);
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				chkmin(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		int x, y; cin >> x >> y;
		int ans = inf; 
		for (int j = 0; j < all[x].size(); j++)
			for (int k = 0; k < all[y].size(); k++)
			{
				int u = all[x][j][0], uw = all[x][j][1], v = all[y][k][0], vw = all[y][k][1];
				chkmin(ans, uw + vw + dis[u][v]);
			}
		cout << ans + w[x] + w[y] << '\n';
	}
}

