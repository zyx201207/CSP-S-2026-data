#include<bits/stdc++.h>
using namespace std;
//kbq
const int maxn = 1e3 + 10;
int c,T;
vector<int> g[maxn];
int n,k,cs[maxn],vis[maxn];
void dfs_main(int dep)
{
	if(dep == k+1)
	{
		
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i]) 
		{
			vis[i] = 1;
			cs[dep] = i;
			dfs_main(dep+1);
			cs[dep] = 0;
			vis[i] = 0;
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++)
			g[i].clear();
		for(int i = 1;i < n;i++)
		{
			int u,v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs_main(1);
	}
	return 0;
}
