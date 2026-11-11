#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int u;
	ll dis;
	bool operator <(node x)const
	{
		return dis>x.dis;
	}
};
struct node2
{
	int u;
	ll w;
};
bool cmp(node2 a,node2 b)
{
	return a.u<b.u;
}
ll w[500010],way[510][510],dis[510][510];
vector<node2> a[510],b[510],ans[500010];
priority_queue<node> q;
bool vis[500010];
void dijkstra(int s)
{
	memset(vis,false,sizeof(vis));
	q.push({s,0});
	vis[s]=true;
	dis[s][s]=0;
	while(!q.empty())
	{
		node c=q.top();
		q.pop();
		for(int i=0;i<b[c.u].size();i++)
		{
			if(dis[s][c.u]+b[c.u][i].w<dis[s][b[c.u][i].u])
			{
				dis[s][b[c.u][i].u]=dis[s][c.u]+b[c.u][i].w;
				if(!vis[b[c.u][i].u])
				{
					vis[b[c.u][i].u]=true;
					q.push({b[c.u][i].u,dis[s][b[c.u][i].u]});
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			way[i][j]=dis[i][j]=1e18;
		}
		ll k,x,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>t;
			a[i].push_back({x,t});
			ans[x].push_back({i,t});
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=0,l=0;k<a[i].size()&&l<a[j].size();)
			{
				if(a[i][k].u==a[j][l].u)
				{
					way[i][j]=way[j][i]=min(way[i][j],a[i][k].w+a[j][l].w);
					k++;
					l++;
				}
				else if(a[i][k].u<a[j][l].u)
				{
					k++;
				}
				else
				{
					l++;
				}
			}
			if(way[i][j]!=INT_MAX)
			{
				b[i].push_back({j,way[i][j]});
				b[j].push_back({i,way[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
	}
	for(int k=1;k<=q;k++)
	{
		ll x,y,minn=1e18;
		cin>>x>>y;
		for(int i=0;i<ans[x].size();i++)
		{
			for(int j=0;j<ans[y].size();j++)
			{
				minn=min(minn,ans[x][i].w+ans[y][j].w+dis[ans[x][i].u][ans[y][j].u]+w[x]+w[y]);
			}
		}
		cout<<minn<<'\n';
	}
	return 0;
}
