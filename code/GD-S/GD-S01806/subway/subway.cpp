#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
	bool operator<(const node xx)const{
		return xx.y<y;
	}
};
int c,n,m,d,q,w[501000],dis[510][510],dist[510][510],vis[510];
vector<node> v[501000];
vector<node> p[510];
priority_queue<node> pq;
void add(int x)
{
	memset(vis,0,sizeof(vis));
	pq.push({x,0});
	dis[x][x]=0;
	while(!pq.empty())
	{
		node u=pq.top();
		pq.pop();
		if(vis[u.x])
		{
			continue;
		}
		vis[u.x]=1;
		for(node i:p[u.x])
		{
			if(dis[x][i.x]>u.y+i.y)
			{
				dis[x][i.x]=u.y+i.y;
				pq.push({i.x,dis[x][i.x]});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=n+1;i<=m+n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			x+=n;
			v[x].push_back({i,y});
			v[i].push_back({x,y});
		}
	}
	for(int i=n+1;i<=m+n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=j+1;k<v[i].size();k++)
			{
				dist[v[i][j].x][v[i][k].x]=min(dist[v[i][j].x][v[i][k].x],v[i][j].y+v[i][k].y);
				dist[v[i][k].x][v[i][j].x]=min(dist[v[i][k].x][v[i][j].x],v[i][j].y+v[i][k].y);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[i].push_back({j,dist[i][j]});
			p[j].push_back({i,dist[i][j]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		add(i);
	}
	for(int i=1;i<=q;i++)
	{
		int ans=1e18;
		int x,y;
		cin>>x>>y;
		x+=n;y+=n;
		for(node j:v[x])
		{
			for(node k:v[y])
			{
				ans=min(ans,j.y+k.y+dis[j.x][k.x]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
