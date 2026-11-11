#include<bits/stdc++.h>
using namespace std;
int test_id,t,n,k;
vector<int> g[1000007];
bitset<1000007> vis,occ;
queue<int> q;
int dis[1000007];
void dfs(int u,int fa)
{
	occ[u] = true;
	for(auto v:g[u])
	{
		if(v==fa||!vis[v])
			continue;
		dfs(v,u);
	}
} 
bool check()
{
	for(int i=1;i<=n;i++)
		occ[i] = false;
	int cnt = 0;
	for(int i=1;i<=n;i++)
		if(vis[i]&&!occ[i])
		{
			cnt++;
			dfs(i,0); 
		}
	return cnt <= 2;
}
int bfs()
{
	fill(dis+1,dis+n+1,0x3f3f3f3f);
	for(int i=1;i<=n;i++)
		if(vis[i])
		{
			q.emplace(i);
			dis[i] = 0;
		}
	int u;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(auto v:g[u])
			if(dis[v]>dis[u]+1)
			{
				dis[v] = dis[u] + 1;
				q.emplace(v);
			}
	}
	return *max_element(dis+1,dis+n+1);
}
int ans = 0x3f3f3f3f;
void get_ans(int cur,int lst)
{
	if(cur==k+1)
	{
		if(check())
			ans = min(ans,bfs());
		return;
	}
	for(int i=lst+1;i<=n;i++)
	{
		vis[i] = true;
		get_ans(cur+1,i);
		vis[i] = false;
	}
}
signed main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>test_id>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		ans = 0x3f3f3f3f;
		get_ans(1,0);
		cout<<ans<<'\n';
	}
}

