#include <iostream> 
#include <vector>
using namespace std;

#define int long long
int dis[505][505];
//O(n^3)=1.xe8? 
//dijkstra O((n log n + n^2)n)=bigger
void floyd(int n)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
vector<pair<int,int> > e[500005];
//sigma(d^2)<=1e7
void add(int s)
{
	int siz=e[s].size();
	for(int i=0;i<siz;i++)
	{
		for(int j=i+1;j<siz;j++)
		{
			int u=e[s][i].first,v=e[s][j].first;
			int wu=e[s][i].second,wv=e[s][j].second;
			dis[u][v]=dis[v][u]=min(dis[u][v],wu+wv);
		}
	}
}
int ans[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ans[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int u,w;
			cin>>u>>w;
			e[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		add(i);
	}
	floyd(n);
	//O(q*d^2)<=4e7
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int su=e[u].size(),sv=e[v].size();
		int minn=1e18;
		for(int i=0;i<su;i++)
		{
			for(int j=0;j<sv;j++)
			{
				int tu=e[u][i].first,tv=e[v][j].first;
				int wu=e[u][i].second,wv=e[v][j].second;
				minn=min(minn,wu+dis[tu][tv]+wv);
			}
		}
		cout<<ans[u]+minn+ans[v]<<'\n';
	}
	return 0;
}
