#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,fa[1000005],dep[1000005],depth[1000005],sz[1000005],num[1000005],now;
vector<int> g[1000005];
struct edge{
	int u,v;
}e[10000005];
vector<int> node;
void dfs1(int u,int f,int l)
{
	fa[u] = f;
	node.push_back(u);
	depth[u] = sz[u] = 1,num[u] = 0;
	for(int v : g[u])
	{
		if(v == f) continue;
		dep[v] = dep[u] + 1;
		dfs1(v,u,l);
		sz[u] += sz[v];
		num[u] += num[v];
		depth[u] = max(depth[u],depth[v] + 1);
	}
	if(depth[u] == l+1) num[u] = 1;
}
void dfs2(int u,int f,int l,int ban)
{
	depth[u] = 1;
	for(int v : g[u])
	{
		if(v == f || v == ban) continue;
		dfs2(v,u,l,ban);
		depth[u] = max(depth[u],depth[v] + 1);
	}
//	cout << u << " " << depth[u] << endl;
	if(depth[u] > l) now++;
}
int number(int rt,int f,int l)
{
	int cnt = 0;
	node.clear(); 
	dep[rt] = 0;
	dfs1(rt,f,l);
	int lca = rt;
	for(int u : node)
	{
		if(num[u] == num[rt] && dep[u] > dep[lca]) lca = u;
	}
	cnt = sz[lca];
	for(int u : node)
	{
		if(depth[u] == l+1) cnt -= sz[u]-1;
	}
//	cout << "lca = " << lca << endl;
//	cout << "cnt = " << cnt << endl;
	if(lca != rt)
	{
		now = 0;
//		cout << "fa_lca" << fa[lca] << endl;
		dfs2(fa[lca],lca,l,f);
		cnt += now;
	}
	if(!cnt) cnt = 1;
	return cnt;
}
void init()
{
	for(int i = 1; i <= n; i++)
	{
		g[i].clear();
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		init();
		for(int i = 1; i < n; i++)
		{
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			e[i] = {u,v};
		}
		ans = n;
		for(int i = 1; i < n; i++)
		{
			int u = e[i].u,v = e[i].v;
//			cout << u << " " << v << ":" << number(u,v,2) << " " << number(v,u,2) << endl;
			int l = 0,r = ans;
			while(l <= r)
			{
				int mid = (l+r)/2;
				if(number(u,v,mid) + number(v,u,mid) <= k) r = mid - 1;
				else l = mid + 1;
			}
			ans = min(ans,l);
//			cout << u << " " << v << " " << ans << " " << r << " " << number(u,v,l)+number(v,u,l) << endl;
		}
//		cout << number(7,4,2) << endl;
		cout << ans << endl;
	}
	return 0;
}
