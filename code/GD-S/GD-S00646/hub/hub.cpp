#include <bits/stdc++.h>
using namespace std;
namespace FastIO{
	const int NN = 1<<17;
	char buf[NN], *p1, *p2;
	#define gt() (p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, NN, stdin), p1 == p2)? EOF:*p1++)
	int read()
	{
		int x = 0, f = 1;
		char c = gt();
		while(c < '0' || c > '9')
		{
			if(c == '-')
				f = -1;
			c = gt();
		}
		while('0' <= c && c <= '9')
			x = x*10+(c^48), c = gt();
		return x*f;
	}
	void wt(int x)
	{
		if(x > 9)
			wt(x/10);
		putchar(x%10^48);
	}
	void write(int x)
	{
		if(x < 0)
		{
			putchar('-');
			x = -x;
		}
		wt(x);
	}
}
using FastIO::read;
using FastIO::write;
const int N = 1e6+10;
int t, n, m, maxdeep, deep[N], fa[N], a[N], root, du, dv, madp[N];
vector<int> g[N];
void dfs1(int u)
{
	if(deep[u] > deep[maxdeep])
		maxdeep = u;
	for(auto v:g[u])
		if(v != fa[u])
		{
			deep[v] = deep[u]+1;
			fa[v] = u;
			dfs1(v);
		}
}
void dfs2(int u)
{
	madp[u] = deep[u];
	for(auto v:g[u])
		if(v != fa[u])
		{
			fa[v] = u;
			deep[v] = deep[u]+1;
			dfs2(v);
			madp[u] = max(madp[u], madp[v]);
		}
}
int dfs3(int u, int dis)
{
	int as = (madp[u]-deep[u] >= dis? 1:0);
	for(auto v:g[u])
		if(v != fa[u] && madp[v]-madp[u] > dis)
			as += dfs3(v, dis);
	return as;
}
bool vis[N];
bool check(int dis)
{
	memset(vis, false, sizeof(vis[0])*(n+1));
	int as = 0, dep = -1;
	for(int u = du; u != root; u = fa[u])
	{
		vis[u] = true;
		if(deep[du]-deep[u] == dis)
			dep = deep[u], as++;
		if(dep != -1)
		{
			while(dep-deep[u] > dis)
				as++, dep--;
			for(auto v:g[u])
				if(v != fa[u] && madp[v]-deep[u]+(dep-deep[u]) > dis && vis[v] == false)
				{
					while(dep > deep[u] && madp[v]-deep[u]+(dep-deep[u]) > dis)
						dep--, as++;
					if(madp[v]-deep[u] > dis)
						as += dfs3(v, dis);
				}
		}
	}
	for(int u = dv; u != root; u = fa[u])
	{
		if(deep[dv]-deep[u] == dis)
			dep = deep[u], as++;
		if(dep)
		{
			while(dep-deep[u] > dis)
				as++, dep--;
			for(auto v:g[u])
				if(v != fa[u] && madp[v]-deep[u]+(dep-deep[u]) > dis)
				{
					while(dep > deep[u] && madp[v]-deep[u]+(dep-deep[u]) > dis)
						dep--, as++;
					if(madp[v]-deep[u] > dis)
						as += dfs3(v, dis);
				}
		}
	}
	if(dep > dis)
		as++;
	return as <= m;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	read();
	t = read();
	while(t--)
	{
		n = read(), m = read();
		for(int i = 1, u, v; i < n; i++)
		{
			u = read(), v = read();
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		deep[1] = 0;
		fa[1] = 0;
		maxdeep = 1;
		dfs1(1);
		du = maxdeep;
		deep[du] = 0;
		fa[du] = 0;
		maxdeep = 1;
		dfs1(du);
		dv = maxdeep;
		int cnt = 0;
		for(int i = dv; i; i = fa[i])
			a[++cnt] = i;
		root = a[(cnt+1)>>1];
		fa[root] = 0;
		deep[root] = 0;
		dfs2(root);
		int l = -1, r = n+1, mid;
		while(l+1 < r)
		{
			mid = (l+r)>>1;
			if(check(mid))
				r = mid;
			else
				l = mid;
		}
		write(r);
		putchar('\n');
		for(int i = 1; i <= n; i++)
			g[i].clear();
	}
	return 0;
}
