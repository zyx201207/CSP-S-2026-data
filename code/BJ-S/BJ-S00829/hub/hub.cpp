#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##KON = (r); i <= i##KON; ++i)
#define per(i, l, r) for(int i = (l), i##KON = (r); i >= i##KON; --i)
#define eb emplace_back
using namespace std;
using ll = long long;
constexpr ll N{2000005}, inf{0x3f3f3f3f3f3f3f3f};
int tid, T, n, k, fa[N], dfn[N], ed[N], vc, st[22][N];
ll q[N], d[N], lvl[N], cnt[N], f[2][N], g[N], dep[N], rev[N];
bitset<N> col;
vector<int> e[N];
void pre(int u)
{
	st[0][dfn[u] = ++vc] = fa[u];
	rev[vc] = u;
	for(int v : e[u]) if(v != fa[u])
	{
		dep[v] = dep[u] + 1;
		fa[v] = u;
		pre(v);
	}
	ed[u] = vc;
}
int Min(int u, int v)
{
	return dfn[u] < dfn[v] ? u : v;
}
void getf(int c, int kon)
{
	rep(u, 1, n)
		d[u] = col[u] == c ? e[u].size() - (u == kon || u == fa[kon]) : 0;
	rep(u, 0, n)
		lvl[u] = cnt[u] = 0;
	int h = 0, t = 0;
	rep(u, 1, n) if(col[u] == c && d[u] == 1)
		q[++t] = u;
	while(h < t)
	{
		int u = q[++h];
		// cout<<"Tp:"<<c<<" "<<u<<" "<<lvl[u]<<"\n";
		for(int v : e[u]) if(col[v] == c)
		{
			if(--d[v] == 1)
				lvl[q[++t] = v] = lvl[u] + 1;
		}
	}
	ll mx = 0;
	rep(i, 1, n) if(col[i] == c)
		mx = max(mx, lvl[i]), ++cnt[lvl[i]];
	per(i, mx - 1, 0)
		cnt[i] += cnt[i + 1];
	rep(i, 0, mx)
		f[c][i] = cnt[i];
}
int lca(int u, int v)
{
	if(u == v)
		return u;
	if(dfn[u] > dfn[v])
		swap(u, v);
	int l = dfn[u] + 1, r = dfn[v], k = __lg(r - l + 1);
	return Min(st[k][l], st[k][r - (1 << k) + 1]);
}
int dis(int u, int v)
{
	return u && v ? dep[u] + dep[v] - 2 * dep[lca(u, v)] : -1;
}
struct D
{
	int u, v, w;
	D(int U = 0, int V = 0) : u{U}, v{V}
	{
		w = dis(u, v);
	}
	bool operator<(const D& o) const
	{
		return w < o.w;
	}
	D operator+(const D& o) const
	{
		return max({*this, o, D(u, o.u), D(u, o.v), D(v, o.u), D(v, o.v)});
	}
};
namespace c2
{
	D f[N], pre[N], suf[N];
	void dfs(int u)
	{
		f[u] = D(u, u);
		for(int v : e[u]) if(v != fa[u])
			dfs(v), f[u] = f[u] + f[v];
	}
	void main()
	{
		dfs(1);
		int ans = n;
		pre[0] = suf[n + 1] = D(0, 0);
		rep(i, 1, n)
			pre[i] = pre[i - 1] + D(rev[i], rev[i]);
		per(i, n, 1)
			suf[i] = suf[i + 1] + D(rev[i], rev[i]);
		rep(i, 2, n)
		{
			D g = pre[dfn[i] - 1] + suf[ed[i] + 1];
			ans = min(ans, max((f[i].w + 1) / 2, (g.w + 1) / 2));
		}
		// cout<<pre[n].w<<endl;
		cout << ans << "\n";
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> tid >> T; T--;)
	{
		cin >> n >> k;
		rep(i, 1, n)
			e[i].clear();
		vc = 0;
		ll ans = n;
		rep(i, 2, n)
		{
			int u, v; cin >> u >> v;
			e[u].eb(v), e[v].eb(u);
		}
		pre(1);
		rep(i, 1, 21) rep(j, 1, n - (1 << i) + 1)
			st[i][j] = Min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		if(tid == 11 || tid == 12)
		{
			c2::main();
			continue;
		}
		int m = (n - 1) / 2;
		rep(i, 2, n)
		{
			if((n > 4000) && (i < (m - 1) / 2 || i > (m + 5) / 2))
				continue;
			rep(j, 1, n)
				col[j] = dfn[i] <= dfn[j] && dfn[j] <= ed[i];
			getf(0, i), getf(1, i);
			rep(j, 0, n)
				g[j] = n;
			rep(j, 0, n)
				g[f[1][j]] = min<ll>(g[f[1][j]], j);
			rep(j, 1, n)
				g[j] = min(g[j], g[j - 1]);
			ll cur = n;
			rep(j, 0, n) if(f[0][j] <= k)
				cur = min(cur, max<ll>(j, g[k - f[0][j]]));
			// cout<<i<<" "<<cur<<endl<<"F: ";
			// rep(j,0,n)cout<<f[0][j]<<" \n"[j==n];
			// rep(j,0,n)cout<<f[1][j]<<" \n"[j==n];
			ans = min(ans, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}