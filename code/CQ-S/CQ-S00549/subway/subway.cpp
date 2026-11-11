#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

bool BEGIN;

const int inf = 1e18, MAX = 1e10;
int c, n, m, d, q;
int w[500010];
int val[510][510], dist[510][510];
vector<PII> sw[500010];
bool vis[510];
bool END;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	memset(val, 0x3f, sizeof(val));
	for(int i = 0;i <= 505;i ++)
	{
		for(int j = 0;j <= 505;j ++) dist[i][j] = inf;
	}
//	cerr << "memory: " << (&END - &BEGIN) / 1024 / 1024 << " MB\n";
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++)
	{
		dist[i][i] = 0;
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++)
		{
			int a, t;
			cin >> a >> t;
			for(PII l : sw[a])
			{
				dist[i][l.first] = min(dist[i][l.first], t + l.second);
				dist[l.first][i] = min(dist[l.first][i], t + l.second);
			}
			sw[a].push_back({i, t});
		}
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			for(int k = 1;k <= n;k ++)
			{
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for(PII i : sw[x])
		{
			for(PII j : sw[y])
			{
				ans = min(ans, dist[i.first][j.first] + i.second + j.second);
			}
		}
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
