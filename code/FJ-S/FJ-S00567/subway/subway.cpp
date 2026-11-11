#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
struct node
{
	int u;
	int times=0;
}t;
int c,n,m,d,q;
queue<node> que;
int into[500005];
bool vis[500005];
int grid[5005][5005];
int bfs(int x,int ex)
{
	t.u=x;
	t.times=into[x];
	vis[x]=1;
	que.push(t);
	while(!que.empty())
	{
		for(int i=1;i<=m;i++)
		{
			if(grid[que.front().u][i]==INF||vis[i]) continue;
			cout<<i<<endl;
			t.u=i;
			vis[i]=1;
			t.times=que.front().times+grid[que.front().u][i];
			que.push(t);
			if(t.u==ex)
			{
				while(!que.empty()) que.pop();
				return t.times+into[ex];
			}
		}
		que.pop();
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			grid[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>into[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,station[500005],cost[500005],cf[500005];
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>station[j]>>cost[j];
			cf[j]=cf[j-1]+cost[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int f=1;f+j<=k;f++)
			{
				grid[station[j]][station[j+f]]=min(grid[station[j]][station[j+f]],cf[j+f]-cf[j-1]);
				grid[station[j+f]][station[j]]=min(grid[station[j]][station[j+f]],cf[j+f]-cf[j-1]);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		memset(vis,0,sizeof(vis));
		cout<<bfs(u,v)<<endl;
	}
	return 0;
}
