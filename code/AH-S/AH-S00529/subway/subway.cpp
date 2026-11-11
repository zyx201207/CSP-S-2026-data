#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0;
	char ch=getchar(),f=1;
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int w[500005];
struct node
{
	int to;
	long long w;
	bool operator < (const node &tmp) const
	{
		return w>tmp.w;
	}
};
vector<node> g[500005],e[505];
long long dis[505][505],d[505][505];
bool vis[505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	read();
	int n=read(),m=read();
	read();
	int Q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		while(k--)
		{
			int a=read(),t=read();
			g[a].push_back({i,t});
		}
	}
	memset(d,-1,sizeof d);
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)g[i].size();j++)
		{
			int u=g[i][j].to;
			for(int k=j+1;k<(int)g[i].size();k++)
			{
				int v=g[i][k].to;
				if(d[u][v]!=-1) d[u][v]=d[v][u]=min(d[u][v],g[i][j].w+g[i][k].w);
				else d[u][v]=d[v][u]=g[i][j].w+g[i][k].w;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(d[i][j]!=-1) e[i].push_back({j,d[i][j]}),e[j].push_back({i,d[i][j]});
	memset(dis,0x3f,sizeof dis);
	for(int s=1;s<=n;s++)
	{
		priority_queue<node> q;
		memset(vis,0,sizeof vis);
		dis[s][s]=0;
		q.push({s,0});
		while(!q.empty())
		{
			int p=q.top().to;
			q.pop();
			if(vis[p]) continue;
			vis[p]=1;
			for(int i=0;i<(int)e[p].size();i++)
			{
				int to=e[p][i].to,w=e[p][i].w;;
				if(dis[s][p]+w<dis[s][to])
				{
					dis[s][to]=dis[s][p]+w;
					if(!vis[to]) q.push({to,dis[s][to]});
				}
			}
		}
	}
	while(Q--)
	{
		int x=read(),y=read();
		long long ans=LLONG_MAX;
		for(int i=0;i<(int)g[x].size();i++)
		{
			int u=g[x][i].to;
			for(int j=0;j<(int)g[y].size();j++)
			{
				int v=g[y][j].to;
				ans=min(ans,g[x][i].w+g[y][j].w+dis[u][v]);
			}
		}
		write(ans+w[x]+w[y]);
		puts("");
	}
	return 0;
}
