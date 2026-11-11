#include <iostream>
#include <vector>
using namespace std;
const int N = 2e6+5;
vector<int> g[N];
int n,k;
int ans;
int fa[N];
int gu[N],gv[N];
vector<int> chs;
bool isc[N];
bool unt[N];
int find(int x)
{
	if (fa[x] == x) return fa[x];
	return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fx] = fy;
}
bool check()
{
	for (int v : chs) fa[v] = v;
	for (int i = 1; i <= n-1; i++) if (isc[gu[i]] && isc[gv[i]]) unite(gu[i],gv[i]);
	for (int i = 1; i <= n; i++) if (isc[i]) unt[find(i)] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += unt[i];
	return cnt <= 2;
}
int anc[N][26];
int dep[N];
void dfs0(int u, int fa)
{
	dep[u] = dep[fa]+1;
	anc[u][0] = fa;
	for (int i = 1; i < 26; i++) anc[u][i] = anc[anc[u][i-1]][i-1];
	for (int v : g[u])
	{
		if (v == fa) continue;
		dfs0(v,u);
	}
}
int LCA(int u, int v)
{
	if (u == v) return u;
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 25; i >= 0; i--)
	{
		if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
	}
	if (u == v) return u;
	for (int i = 25; i >= 0; i--)
	{
		if (anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}
int cal()
{
	int maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		int d = 1e9;
		for (int j = 1; j <= n; j++)
		{
			if (isc[j])
			{
				int x = LCA(i,j);
				d = min(d,dep[i]+dep[j]-2*dep[x]);
			}
		}
		maxn = max(maxn,d);
	} 
	return maxn;
}
void dfs(int p, int cnt)
{
	if (cnt > k) return ;
	if (p > n)
	{
		if (cnt == k && check()) ans = min(ans,cal());
		return ;
	}
	dfs(p+1,cnt);
	chs.push_back(p);
	isc[p] = 1;
	dfs(p+1,cnt+1);
	chs.pop_back();
	isc[p] = 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n-1; i++)
		{
			cin >> gu[i] >> gv[i];
			int u = gu[i], v = gv[i];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs0(1,0);
		ans = 1e9;
		dfs(1,0);
		cout << ans << "\n";
	}
	return 0;
}

/*
0 1
5 2
1 2
2 3
3 4
4 5

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
*/
