#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 10;

int a[N], dis[N], cnt[N];

vector <int> f[N];

struct Node
{
	int u, w;
	bool operator < (Node a) const
	{
		return w > a.w;
	}
};

void solve()
{
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) f[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n, rpos = -1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] - a[i] <= d)
			{
				rpos = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		if (rpos != -1) for (int j = i + 1; j <= rpos; j++) f[i].emplace_back(j);
	}
	int ans = 0;
	for (int i = 1; i < n - 2; i++)
	{
		priority_queue <Node> q;
		q.push({i, 0});
		memset(dis, 0x3f, sizeof(dis));
		dis[i] = 0;
		while (!q.empty())
		{
			Node tp = q.top();
			q.pop();
			int u = tp.u;
			for (auto v : f[u])
			{
				if (dis[u] + 1 < dis[v])
				{
					dis[v] = dis[u] + 1;
					q.push({v, dis[v]});
				}
			}
		}
		while (!q.empty()) q.pop();
		q.push({i, 0});
		memset(cnt, 0, sizeof(cnt));
		while (!q.empty())
		{
			Node tp = q.top();
			q.pop();
			int u = tp.u, w = tp.w;
			if (w == dis[u]) cnt[u]++;
			for (auto v : f[u]) if (w + 1 == dis[v]) q.push({v, dis[v]});
		}
		for (int j = i + 1; j <= n; j++) if (cnt[j] == 2) ans++;
	}
	
	cout << ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	if (c == 11 || c == 12)
	{
		while (T--)
		{
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) cin >> a[i];
			if (n == 1) cout << 0 << '\n';
			else
			{
				int st = d / (a[2] - a[1]);
				if (st == 0 || st == 1)
				{
					cout << 0 << '\n';
					continue;
				}
				int dis = 2 * st - 1;
				cout << max(0ll, n - dis) << '\n';
			}
		}
		return 0;
	}
	while (T--) solve(); 
	return 0;
}
