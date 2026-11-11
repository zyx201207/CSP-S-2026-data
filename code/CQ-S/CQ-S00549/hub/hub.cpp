#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

bool BEGIN;

namespace FIO
{
	char buf[1 << 22], *p1, *p2;
	char c;
	int f;
	#define gc() ((p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin)), *p1 ++)

	void read(int &res)
	{
		res = 0;
		f = 1;
		c = gc();
		for(;!isdigit(c);c = gc()) if(c == '-') f = -1;
		for(;isdigit(c);c = gc()) res = (res << 3) + (res << 1) + (c & 15);
		res = res * f;
	}
}

int c, t;
int n, k;
vector<int> g[1000010];
int len[1000010];
int dep[1000010];
int dfn[1000010], dfc;
int st[1000010][21], lgn[1000010], pw2[21];
int stk[1000010], top;
vector<int> nd;
int ds;

int compare(int x, int y)
{
	return (dfn[x] < dfn[y] ? x : y);
}

void dfs1(int u, int fa)
{
	dfn[u] = ++ dfc;
	dep[u] = dep[fa] + 1;
	st[dfn[u]][0] = fa;
	for(int v : g[u])
	{
		if(v == fa) continue;
		dfs1(v, u);
	}
}

void init_ST()
{
	pw2[0] = 1;
	for(int i = 1;i <= 20;i ++) pw2[i] = pw2[i - 1] * 2;
	for(int i = 2;i <= n;i ++) lgn[i] = lgn[i >> 1] + 1;
	for(int t = 1;t <= 20;t ++)
	{
		for(int i = 1;i + pw2[t] - 1 <= n;i ++)
		{
			st[i][t] = compare(st[i][t - 1], st[i + pw2[t - 1]][t - 1]);
		}
	}
}

int get_lca(int u, int v)
{
	if(u == v) return u;
	if(dfn[u] > dfn[v]) swap(u, v);
	u = dfn[u] + 1, v = dfn[v];
	int t = lgn[v - u + 1];
	return compare(st[u][t], st[v - t + 1][t]);
}

bool vis[1000010];

PII init(int u, int fa, int p)
{
	vis[u] = len[u] = 0;
	int mx = 0;
	for(int v : g[u])
	{
		if(v == fa) continue;
		PII t = init(v, u, p);
		len[u] = max(len[u], t.first);
		mx = max(mx, t.second);
	}
	if(len[u] >= p + mx)
	{
		vis[u] = 1;
		cerr << "choose " << u << "\n";
		ds ++;
		nd.push_back(u);
		return {0, p};
	}
	if(mx) return {0, max(0ll, mx - 1)};
	return {len[u] + 1, 0};
}

int res, qh;
vector<int> nw[1000010];

void calc(int u)
{
//	cerr << u << " node\n";
	qh ++;
	for(int v : nw[u])
	{
		calc(v);
		qh += dep[v] - dep[u] - 1;
//		cerr << dep[v] - dep[u] - 1 << "cs\n";
		res = max(res, dep[v] - dep[u] - 1);
	}
}

bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}

bool check(int p)
{
	cerr << "fz " << p << "\n";
	nd.clear();
	ds = 0;
	PII T = init(1, 0, p);
//	cerr << "init success\n";
	if(T.second == 0)
	{
		ds ++;
		nd.push_back(1);
	}
	if(ds == 1) return 1;
	sort(nd.begin(), nd.end(), cmp);
	top = 0;
	int root = get_lca(nd[0], nd[nd.size() - 1]);
	for(int i = 1;i < nd.size();i ++)
	{
		int LCA = get_lca(nd[i], nd[i - 1]);
		cerr << "now " << nd[i - 1] << " " << nd[i] << " " << LCA << "\n";
		vis[LCA] = 1;
		if(i == 1)
		{
			stk[++ top] = LCA;
			if(nd[i] != LCA) stk[++ top] = nd[i];
			if(LCA != nd[0]) nw[LCA].push_back(nd[i - 1]), cerr << "link" << LCA << " " << nd[i - 1] << "\n";
			continue;
		}
		while(top && dfn[stk[top]] > dfn[LCA])
		{
			cerr << top << " " << stk[top] << " ";
			if(stk[top] == stk[top - 1])
			{
				top --;
				continue;
			}
			if(top == 1 || dfn[stk[top - 1]] < dfn[LCA]) nw[LCA].push_back(stk[top]);
			else nw[stk[top - 1]].push_back(stk[top]);
			top --;
		}
		if(stk[top] == LCA) nw[LCA].push_back(nd[i]);
		else stk[++ top] = LCA;
	}
	while(top)
	{
		cerr << stk[top] << "clear\n";
		if(top > 1) nw[stk[top - 1]].push_back(stk[top]), cerr << "link" << stk[top - 1] << " " << stk[top] << "\n";
		top --;
	}
	qh = res = 0;
	calc(root);
	for(int i = 1;i <= n;i ++)
	{
		vis[i] = 0;
		nw[i].clear();
	}
	nd.clear();
	cerr << "res: " << qh << " " << res << "\n";
	if(qh - res <= k) return 1;
	return 0;
}

bool END;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cerr << "memory: " << (int)(&BEGIN - &END) << "\n";
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i ++)
		{
			g[i].clear();
			dfn[i] = 0;
			dep[i] = 0;
		}
		for(int i = 1;i < n;i ++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1, 0);
		cerr << "dfs1 succeed!\n";
		int l = 0, r = n, mid;
		while(l < r)
		{
			mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout << r << "\n"; 
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
5 2
1 2
2 3
3 4
4 5
*/
