#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
int n, k, ans, fa[N], vis[N];
bool flag[N];
pair<int, int> start[M];
vector<int> e[N];
int check(int l, int r)
{
	int nk = k;
	for (int i = 1; i <= n; i++) flag[i] = 0;
	if (nk == 1)
	{
		flag[l] = 1;
		nk--;
	}
	else
	{
		flag[l] = flag[r] = 1;
		nk -= 2;
	}
	queue<int> q;
	do
	{
//		cout << k << '\n';
		while (q.size()) q.pop();
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			if (flag[i]) q.push(i), vis[i] = 1, fa[i] = i;
		}
//		cout << "check\n";
		while (q.size())
		{
			int now = q.front(); q.pop();
//			cout << now << '\n';
			for (int v : e[now])
			{
				if (vis[v]) continue;
				fa[v] = now;
				vis[v] = vis[now] + 1;
				q.push(v);
			}
		}
		int maxx = -1, id = l;
		for (int i = 1; i <= n; i++) 
		{
//			cout << fa[i] << ' ' << vis[i] << '\n';
			if (maxx < vis[i]) maxx = vis[i], id = i;
		}
//		cout << '\n';
		if (k)
		{
			while (vis[fa[id]] != 1) id = fa[id];
			flag[id] = 1;
			k--;
			ans = min(ans, maxx - 1);
		}
	}while (k);
}
void solve()
{
	mt19937 rd(time(0));
	int cnt = 0;
	cin >> n >> k;
	ans = n;
	for (int i = 1, u, v; i < n; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if (n <= 1000)
	{
		for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) start[++cnt] = {i, j};
		shuffle(start + 1, start + cnt + 1, rd);
	}
	else for (int i = 1; i <= 1000; i++) start[i] = {rd() % n + 1, rd() % n + 1};
//	cout << "checker\n";
//	if (n <= 100)
//	{
//		for (int i = 1; i <= cnt; i++) cout << start[i].first << ' ' << start[i].second << '\n';
//	}
	for (int i = 1; i <= min(n * (n - 1) / 2, 100); i++)
	{
//		cout << "check " << i << '\n';
		check(start[i].first, start[i].second);
	}
	cout << ans << '\n';
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
//	freopen("hub4.in", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
