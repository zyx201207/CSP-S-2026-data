#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],dis[505][505];
vector<pair<long long,long long> > e[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back({i,y}); 
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int x=0;x<e[i].size();x++)
		{
			for(int y=0;y<e[i].size();y++)
			{
				if(x!=y)
				{
					pair<long long,long long> t1,t2;
					t1=e[i][x];
					t2=e[i][y];
					dis[t1.first][t2.first]=min(dis[t1.first][t2.first],t1.second+t2.second);
				}
			}
		}
	}
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			for(int z=1;z<=n;z++)
			{
				dis[y][z]=min(dis[y][z],dis[y][x]+dis[x][z]);
			}
		}
	}
	while(q--)
	{
		long long u,v,ans=LLONG_MAX;
		cin>>u>>v;
		for(int x=0;x<e[u].size();x++)
		{
			for(int y=0;y<e[v].size();y++)
			{
				ans=min(ans,w[u]+w[v]+e[u][x].second+e[v][y].second+dis[e[u][x].first][e[v][y].first]);
			}
		}
		cout<<ans<<endl;
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
