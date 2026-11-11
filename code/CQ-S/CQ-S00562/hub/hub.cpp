#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e6 + 5;
// bool __st__;
int n, k;
vector<int> g[N];
vector<int> T[2][N];
int mx[N], cmx[N];
void dfs(int u, int fa, int op)
{
	mx[u] = -n - 1, cmx[u] = -n - 1;
	for (int v : T[op][u])
		if (v != fa)
		{
			dfs(v, u, op);
			int val = mx[v] + 1;
			if (val > mx[u]) swap(val, mx[u]);
			if (val > cmx[u]) swap(val, cmx[u]);
		}
	int val = 0;
	if (val > mx[u]) swap(val, mx[u]);
	if (val > cmx[u]) swap(val, cmx[u]);
}
void changeRoot(int u, int fa, int op)
{
	for (int v : T[op][u])
		if (v != fa)
		{
			int val = ((mx[v] + 1) == mx[u] ? cmx[u] + 1 : mx[u] + 1);
			if (val > mx[v]) swap(val, mx[v]);
			if (val > cmx[v]) swap(val, cmx[v]);
			changeRoot(v, u, op);
		}
}
vector<int> grp[2];
bool bel[N];
void dfsAdd(int u, int fa, int op)
{
	grp[op].push_back(u);
	bel[u] = op;
	for (int v : g[u])
		if (v != fa)
		{
			T[op][u].push_back(v);
			T[op][v].push_back(u);
			dfsAdd(v, u, op);
		}
}
struct node
{
	int mxd, u, fa;
	bool operator < (const node &T) const & { return mxd < T.mxd; } 
};
priority_queue<node> q;
int cut(int u, int v)
{
	for (int i = 1; i <= n; i++)
		T[0][i].clear(), T[1][i].clear();
	grp[0].clear(), grp[1].clear();
	dfsAdd(u, v, 0);
	dfsAdd(v, u, 1);
	dfs(u, v, 0);
	dfs(v, u, 1);
	changeRoot(u, v, 0);
	changeRoot(v, u, 1);
	int mn0 = u, mn1 = v;
	for (int x : grp[0])
		if (mx[x] < mx[mn0])
			mn0 = x;
	for (int x : grp[1])
		if (mx[x] < mx[mn1])
			mn1 = x;
	u = mn0, v = mn1;
	dfs(u, 0, 0);
	dfs(v, 0, 1);
	while (q.size()) q.pop();
	for (int x : T[0][u])
		q.push({mx[x], x, u});
	for (int x : T[1][v])
		q.push({mx[x], x, v});
	int nk = k;
	nk -= 2;
	while (q.size() && nk)
	{
		node sbcpp14 = q.top();
		q.pop();
		int now = sbcpp14.u;
		int op = bel[now];
		nk--;
		for (int v : T[op][now])
			if (v != sbcpp14.fa)
				q.push({mx[v], v, now});
	}
	return !q.size() ? 0 : q.top().mxd;
}
void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 1, u, v; i < n; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = n + 1;
	for (int i = 1; i <= n; i++)
		for (int v : g[i])
			if (v > i)
				ans = min(ans, cut(i, v));
	cout << ans + 1 << '\n';
}
// bool __ed__;
// void PrintMem() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
signed main()
{
	// PrintMem();
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}