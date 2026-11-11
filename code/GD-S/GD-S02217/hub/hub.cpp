#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int c,t,n,k,u,v,ans=1e9;
vector<int> g[1001];
bool flag[1001],vis[1001];
void dfs(int u)
{
	vis[u]=true;
	for(int v:g[u])
	{
		if(flag[v]&&!vis[v])
		{
			dfs(v);
		}
	}
}
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=flag[i];
	}
	if(cnt!=k) return false;
	cnt=0;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(flag[i]&&!vis[i])
		{
			cnt++;
			dfs(i);
		}
	}
	return (cnt<=2);
}
int count()
{
	int r=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		int dis=1128;
		memset(vis,false,sizeof(vis));
		vis[i]=true;
		queue<pair<int,int>> q;
		q.push({i,0});
		while(!q.empty())
		{
			auto p=q.front();
			int u=p.first,d=p.second;
			q.pop();
			for(int v:g[u])
			{
				if(!vis[v])
				{
					if(flag[v])
					{
						dis=d+1;
						break;
					}
					q.push({v,d+1});
				}
			}
			if(dis!=1128) break;
		}
		r=max(r,dis);
	}
	return r;
}
void solve(int x)
{
	if(x==n+1)
	{
		if(check()) ans=min(ans,count());
		return;
	}
	flag[x]=true;
	solve(x+1);
	flag[x]=false;
	solve(x+1);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		solve(1);
		cout<<ans<<"\n";
	}
	return 0;
}
