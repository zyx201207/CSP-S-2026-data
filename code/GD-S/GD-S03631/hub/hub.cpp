#include <bits/stdc++.h>
#define int long long
#define inf (int)(1e9)
#define pii pair<int,int> 
using namespace std;

const int N = 35;
int c,T,n,k,fa[N],dep[N],dfn[N],t,st[N][25];
vector<int> e[N];
vector<int> vis(N + 5,0),pt;
set<int> rt;
pii edge[N];

void init()
{
	for(int i = 1;i <= n;i++) fa[i] = i,dep[i] = 0,dfn[i] = 0,e[i].clear(),edge[i] = {0,0};
	for(int k = 0;k < 25;k++) for(int i = 1;i <= n;i++) st[i][k] = 0;
	vis.clear();
	rt.clear();
	pt.clear();
	t = 0;
}

void dfs(int u,int fa)
{
	dep[u] = dep[fa] + 1,dfn[u] = ++t,st[dfn[u]][0] = fa;
	for(int& v : e[u]) if(v != fa) dfs(v,u);
}

int comp(int x,int y)
{
	return (dep[x] < dep[y] ? x : y);
}

void reset()
{
	int logn = __lg(n);
	for(int k = 1;k <= logn;k++)
		for(int i = 1;i <= n;i++)
			st[i][k] = comp(st[i][k - 1],st[i + (1 << (k - 1))][k - 1]);
}

int lca(int u,int v)
{
	if(u == v) return u;
	if(dfn[u] > dfn[v]) swap(u,v);
	int l = dfn[u] + 1,r = dfn[v],len = __lg(r - l + 1);
	return comp(st[l][len],st[r - (1 << len) + 1][len]); 
}

int getfa(int x)
{
	return (fa[x] == x ? fa[x] : (fa[x] = getfa(fa[x])));
}

void merge(int u,int v)
{
	int x = getfa(u),y = getfa(v);
	if(x == y) return;
	fa[x] = y;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		init();
		cin >> n >> k;
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			edge[i] = {u,v};
		}
		dfs(1,0);
		reset();
		int ans = inf;
		for(int st = 0;st < (1 << n);st++)
		{
			if(__builtin_popcount(st) != k) continue;
			vis.clear();
			vis.resize(n + 5,0);
			rt.clear();
			pt.clear();
			for(int i = 1;i <= n;i++) fa[i] = i;
			for(int p = st;p;p &= (p - 1))
			{
				int u = __builtin_ctz(p) + 1;
				vis[u] = 1,pt.push_back(u);
			}
			for(int i = 1;i < n;i++) if(vis[edge[i].first] && vis[edge[i].second]) merge(edge[i].first,edge[i].second);
			for(int i = 1;i <= n;i++)
			{
				if(!vis[i]) continue;
				rt.insert(getfa(i));
			}
			if(rt.size() > 2) continue;
			int r = 0;
			for(int i = 1;i <= n;i++)
			{
				int d = inf;
				for(int& p : pt) d = min(d,dep[i] + dep[p] - (dep[lca(i,p)] << 1));
				r = max(r,d);
			}
			ans = min(ans,r);
		}
		cout << ans << "\n";
	}
	return 0;
}
