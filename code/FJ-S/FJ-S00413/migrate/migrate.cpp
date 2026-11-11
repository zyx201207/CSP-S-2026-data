# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 2e6 + 10, _N = 5e3 + 10;
int c;
int n, d;
int x[N];
vector < int > g[N];
int dis[_N][_N];
int ans;
int cnt[_N];
void bfs(int s)
{
	queue < int > q;
	q.push(s);
	dis[s][s] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : g[u])
		{
			if (~dis[s][v]) continue;
			else
			{
				dis[s][v] = dis[s][u] + 1;
				q.push(v);
			}
		}
	}
}
void solve()
{
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	if (c <= 10)
	{
		for (int i = 1; i <= n; i ++) g[i].clear();
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				if (x[j] - x[i] <= d)
				{
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		memset(dis, -1, sizeof dis);
		for (int i = 1; i <= n; i ++) bfs(i);
		for (int i = 1; i <= n; i ++)
		{
			memset(cnt, 0, sizeof cnt);
			cnt[i] = 1;
			for (int j = i + 1; j <= n; j ++)
			{
				int _ = 0;
				for (int x : g[j])
				{
					if (dis[i][j] == dis[i][x] + 1) cnt[j] += cnt[x];
				}
				if (cnt[j] == 2) ans ++;
			}
		}
		cout << ans << '\n';
	}
	else if (c <= 12)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (x[i] - x[1] > d) break;
			cnt ++; 
		}
		cnt --;
		if (cnt <= 1) cout << 0 << '\n';
		else cout << max(0ll, (n - 1 - 2 * (cnt - 1))) << '\n';
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> c >> T;
	while (T --) solve();
	return 0;
}

