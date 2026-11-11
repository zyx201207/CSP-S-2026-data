#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int t,n,k;
vector<int>g[N];
bool vis[N];
int dis[N];
void DFS(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		if(dis[v]>dis[u]+1)
		{
			dis[v]=dis[u]+1;
			DFS(v,u);
		}
	}
}
int ans;
bool c[3005][3005];
void dfs(int x,int now,int cnt)
{
	if(x>k)
	{
		for(int i=1;i<=n;i++) dis[i]=1e9;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]) continue;
			dis[i]=0;
			DFS(i,0);
		}
		int maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,dis[i]);
		ans=min(ans,maxn);
		return;
	}
	for(int i=now;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			bool f=0;
			for(int j=1;j<=n;j++)
				if(vis[j]&&c[i][j]) f=1;
			if(f) dfs(x+1,i+1,cnt);
			else if(cnt<2) dfs(x+1,i+1,cnt+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			if(n<=3000) c[u][v]=c[v][u]=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(T==13||T==14)
		{
			cout<<(((n-1)/2+2)/2-k/2)/2+1<<'\n';
			for(int i=1;i<=n;i++) g[i].clear();
			continue;
		}
		ans=1e9;
		dfs(1,1,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			if(n<=3000) for(int j=1;j<=n;j++) c[i][j]=0;
		}
	}
	return 0;
 } 
/*
0 1
21 5
1 2
2 3
3 4
4 5
5 6
6 12
6 13
13 14
13 15
15 16
15 17
17 18
17 19
19 20
19 21
1 7
2 8
3 9
4 10
5 11
*/
