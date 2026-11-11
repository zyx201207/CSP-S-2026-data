#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

namespace FastIO
{
	const int S = 1 << 21;
	char ibuf[S],*p1 = ibuf,*p2 = ibuf,obuf[S],*op = obuf;
	inline char gc()
	{
		if(p1 == p2)
		{
			p2 = (p1 = ibuf) + fread(ibuf,1,S,stdin);
			if(p1 == p2) return EOF;
		}
		return *p1++;
	}
//	inline int read() // without f !!!
//	{
//		int x = 0; char c = gc();
//		while(c < '0' || c > '9') c = gc();
//		while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = gc();
//		return x;
//	}
	inline int read() // without f !!!
	{
		int x = 0; char c = getchar();
		while(c < '0' || c > '9') c = getchar();
		while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
		return x;
	}
}
using FastIO::read;

int kase,n,k; vector<int> G[N];
int f[N],dep[N],siz[N],son[N];
void dfs1(int x,int fa)
{
	f[x] = fa,dep[x] = dep[fa] + 1,siz[x] = 1;
	for(int u : G[x]) if(u != fa)
	{
		dfs1(u,x); siz[x] += siz[u];
		if(siz[u] > siz[son[x]]) son[x] = u;
	}
}
int dfn[N],DFN = 0,top[N];
void dfs2(int x,int t)
{
	dfn[x] = ++DFN,top[x] = t;
	if(!son[x]) return; dfs2(son[x],t);
	for(int u : G[x]) if(u != f[x] && u != son[x]) dfs2(u,u);
}
int LCA(int u,int v)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] > dep[top[v]]) swap(u,v);
		v = f[top[v]];
	}
	if(dep[u] > dep[v]) swap(u,v);
	return u;
}
int dis(int u,int v) { return dep[u] + dep[v] - 2 * dep[LCA(u,v)]; }

//bool mark[N]; int cnt[N],dep2[N];
//void dfs(int x,int fa)
//{
//	dep2[x] = 0;
//	for(int u : G[x]) if(u != fa)
//	{
//		if(mark[u]) continue;
//		dfs(u,x),dep2[x] = max(dep2[]);
//	}
//}
//
//int solve1()
//{
//	int ans = n;
//	for(int x = 1; x <= n; x++)
//	{
//		int now = 0;
//		for(int i = 1; i <= n; i++)
//		{
//			if(dfn[i] >= dfn[x] && dfn[i] <= dfn[x] + siz[x] - 1) continue;
//			now = max(now,dis(i,x)); if(now > ans) break;
//		}
//		if(now > ans) continue;
//		maxd = 0; dfs(x,f[x],x);
//		int s = 0;
//		for(int i = maxd; i >= now; i--)
//			if(s + cnt[i] > k - 1) { now = max(now,i); break; }
//			else s += cnt[i];
//		ans = min(ans,now);
// 		dfs0(x,f[x],x);
//	}
//	for(int x = 1; x <= n; x++)
//		for(int y = x + 1; y <= n; y++)
//		{
//			int now = 0;
//			for(int i = 1; i <= n; i++)
//			{
//				if(dfn[i] >= dfn[x] && dfn[i] <= dfn[x] + siz[x] - 1) continue;
//				if(dfn[i] >= dfn[y] && dfn[i] <= dfn[y] + siz[y] - 1) continue;
//				now = max(now,min(dis(i,x),dis(i,y)));
//				if(now > ans) break;
//			}
// 			if(now > ans) continue;
// 			maxd = 0,mark[x] = mark[y] = 1;
// 			dfs(x,f[x],x),dfs(y,f[y],y);
// 			int s = 0;
// 			for(int i = maxd; i >= now; i--)
// 				if(s + cnt[i] > k - 2) { now = max(now,i); break; }
// 				else s += cnt[i];
// 			ans = min(ans,now);
// 			dfs0(x,f[x],x),dfs0(y,f[y],y);
// 			mark[x] = mark[y] = 0;
//		}
//	return ans;
//}

int d[N],lst[N],nxt[N],vis[N];
void DFS(int x,int fa)
{
	d[x] = d[fa] + 1,lst[x] = fa;
	for(int u : G[x]) if(u != fa && !vis[u]) DFS(u,x);
}
void solve2()
{
	d[1] = 0; DFS(1,0);
	int u = 1;
	for(int i = 2; i <= n; i++)
		if(d[i] > d[u]) u = i;
	d[u] = 0; DFS(u,0); int v = u;
	for(int i = 1; i <= n; i++)
		if(d[i] > d[v]) v = i;
	int p = v,len = d[v] / 2;
	while(len--) p = lst[p];
	int x = p,y = p;
	if(d[v] & 1) y = lst[p];
	fill(vis + 1,vis + n + 1,0);
	p = v; while(p) vis[p] = 1,nxt[lst[p]] = p,p = lst[p];
	fill(d + 1,d + n + 1,0);
	DFS(x,0);
	int anss = 0,ans = n;
	for(int i = 1; i <= n; i++) anss = max(anss,d[i]);
	fill(d + 1,d + n + 1,0);
	DFS(y,0);
	for(int i = 1; i <= n; i++) anss = max(anss,d[i]);
	for(int i = 0; i <= d[v] / 2; i++)
	{
		ans = min(ans,max(i,anss));
		x = nxt[x],y = lst[y],anss++;
	}
	cout << ans << "\n";
}
void solve()
{
	n = read(),k = read();
	for(int i = 1,u,v; i < n; i++)
		u = read(),v = read(),G[u].push_back(v),G[v].push_back(u);
	
	solve2();
//	if(kase <= 6) printf("%d\n",solve1());
//	printf("%d\n",solve2());
//	else printf("%d\n",solve3());
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T; kase = read(),T = read();
	while(T--) solve();
	return 0;
}
