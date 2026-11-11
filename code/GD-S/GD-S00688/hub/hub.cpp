#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void gmax(int &x, int y)
{
	if (y > x) x = y;
}
void gmin(int &x, int y)
{
	if (y < x) x = y;
}
const int N = 1e6 + 5, LGN = 20, inf = 1e18;
int CID, T, n, k, dfn[N], dep[N], dfntim, ans;
int f[N][LGN + 5];
vector<int> vec[N];
void gtree(int now, int from)
{
	dep[now] = dep[from] + 1;
	f[now][0] = from;
	for (int i = 1;i <= LGN;i++) f[now][i] = 0;
	for (int i = 1;(1 << i) <= dep[now];i++) f[now][i] = f[f[now][i - 1]][i - 1];
	for (int to : vec[now])
	{
		if (to == from) continue;
		gtree(to, now);
	}
}
int lca(int x, int y)
{
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = LGN;i >= 0;i--)
	{
		if (dep[f[y][i]] >= dep[x]) y = f[y][i];
	}
	if (x == y) return x;
	for (int i = LGN;i >= 0;i--)
	{
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i]; 
	}
	return f[x][0];
}
int dis(int x, int y)
{
	return dep[x] + dep[y] - (dep[lca(x, y)] << 1);
}
vector<int> sta;
bool vis[N];
int fa[N], siz[N];
int find(int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}
void merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return;
	if (siz[x] < siz[y]) swap(x, y);
	fa[y] = x, siz[x] += siz[y];
}
void gans(int rest, int lst)
{
	if (lst + rest > n) return;
	if (!rest)
	{
		for (int i : sta) fa[i] = i, siz[i] = 1;
		for (int i : sta)
		{
			for (int j : vec[i])
			{
				if (vis[j]) merge(i, j);
			}
		}
		int cnt = 0;
		for (int i : sta)
		{
			if (i == find(i)) cnt++;
			if (cnt > 2) return;
		}
		int tmp = 0;
//		for (int i : sta) cout<<i<<" , ";
//		endl;
		for (int i = 1;i <= n;i++)
		{
			if (vis[i]) continue;
			int tdis = inf;
			for (int j : sta) gmin(tdis, dis(i, j));
			gmax(tmp, tdis);
//			cout<<i<<" : "<<tdis, endl;
		}
//		cout<<tmp, endl;
		gmin(ans, tmp);
		return;
	}
	for (int i = lst + 1;i <= n;i++)
	{
		if (vis[i]) continue;
		sta.eb(i);
		vis[i] = 1;
		gans(rest - 1, i);
		vis[i] = 0;
		sta.pop_back();
	}
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w" , stdout);
	CID = read(), T = read();
	while (T--)
	{
		n = read(), k = read();
		for (int i = 1;i <= n;i++) vec[i].clear();
		for (int i = 1;i < n;i++)
		{
			int u = read(), v = read();
			vec[u].eb(v);
			vec[v].eb(u);
		}
		dfntim = 0;
		gtree(1, 0);
		ans = n + 1;
		sta.clear();
		gans(k, 0);
		write(ans), endl;
	}
	return 0;
}
