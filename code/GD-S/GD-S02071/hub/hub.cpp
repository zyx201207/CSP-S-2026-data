#include <bits/stdc++.h>
#define ft first
#define sd second
#define md make_pair
#define pb push_back
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = gc();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = gc();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 1e6 + 5;
vector<int> e[N];
bool flag[N], vis[N];
int dep[N];
int f[20][N];
void dfs1(int u, int fa)
{
	dep[u] = dep[f[0][u] = fa] + 1;
	for (int i = 1; i < 20; i++) f[i][u] = f[i - 1][f[i - 1][u]];
	for (int v : e[u]) if (v ^ fa) dfs1(v, u);
}
int LCA(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--) 
		if (dep[f[i][y]] >= dep[x]) y = f[i][y];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
	return f[0][x];
}
ll dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[LCA(u, v)]; }
void dfs2(int u)
{
	vis[u] = true;
	for (int v : e[u]) if (!vis[v] && flag[v]) dfs2(v);
}
namespace subA {
	void solve()
	{
		int n = read(), k = read();
		for (int i = 1; i <= n; i++) e[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u = read(), v = read();
			e[u].pb(v); e[v].pb(u);
		}
		if (n == k) return puts("0"), void();
		if (n / 2 <= k) return puts("1"), void();
		int m = n / 2 + 2;
		if (m % 4 == 0)
		{
			writech(max(2, m / 4 - k / 4), '\n');
		}
		else if (m % 4 == 2)
		{
			writech(max(2, m / 4 - (k - 2) / 4), '\n');
		}
		else if (m % 4 == 1)
		{
			writech(max(2, m / 4 - (k - 1) / 4 + (k == 2)), '\n');
		}
		else 
		{
			writech(max(2, m / 4 - (k + 1) / 4 + (k == 2)), '\n');
		}
	}
}
void solve()
{
	int n = read(), k = read();
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i < n; i++)
	{
		int u = read(), v = read();
		e[u].pb(v); e[v].pb(u);
	}
	dfs1(1, 0);
	ll ans = 1e18;
	for (int S = 0; S < (1 << n); S++)
	{
		if (__builtin_popcount(S) != k) continue;
		for (int i = 1; i <= n; i++) flag[i] = vis[i] = false;
		for (int i = 1; i <= n; i++)
			if (S & (1 << (i - 1)))
				flag[i] = true;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (S & (1 << (i - 1)))
			{
				if (vis[i]) continue;
				cnt++;
				dfs2(i);
			}
		if (cnt > 2) continue;
		ll res = 0;
		for (int i = 1; i <= n; i++)
		{
			ll tmp = 1e18;
			for (int j = 1; j <= n; j++)
				if (S & (1 << (j - 1)))
					tmp = min(tmp, dist(i, j));
			res = max(res, tmp);
		}
//		cerr << S << " " << res << endl;
		ans = min(ans, res);
	}
	writech(ans, '\n');
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read(), T = read();
//	c = 13;
	if (c == 13 || c == 14)
	{
		while (T--) subA::solve();
		return 0;
	}
	while (T--) solve();
	return 0;
}
/*
start coding at 16:09
finish coding bruteforce 15pts at 16:23
start coding k = 2 at 17:20
oh i dont know how to solve k = 2
finish coding k = 2 & bf 30pts at (failed)
start coding A at 17:31 
finish coding A(25pts) at 17:47
*/
