#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define inf 1e18
using namespace std;
constexpr int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N];
int mndis[N][N];	//trough single station min dis between lines -->final min dis between lines
vector<PII> g[N];	//line's graph
vector<PII> sta[M];	//station to line dis
int dis[N];
bool vis[N];
//void dij(int id)//dij without queue
//{
//	for(int i=1;i<=n;i++)	dis[i]=inf,vis[i]=0;
//	dis[id]=0;
//	int u=id;
//	while(u)
//	{
//		vis[u]=1;
//		for(PII x:g[u])
//		{
//			int v=x.first,w=x.second;
//			if(dis[v]>w+dis[u])	dis[v]=w+dis[u];
//		}
//		int nxtu=0;
//		for(int i=1;i<=n;i++)
//		{
//			if(!vis[i]&&(nxtu==0||dis[i]<dis[nxtu]))	nxtu=i;
//		}
//		u=nxtu;
//	}
//	for(int i=1;i<=n;i++)	mndis[id][i]=dis[i];
//}
void floyd()	//floyd nb
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)	
				mndis[j][k]=min(mndis[i][j]+mndis[i][k],mndis[j][k]);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++)	cin>>a>>t,sta[a].push_back({i,t});
	}
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	mndis[i][j]=inf;
	for(int i=1;i<=n;i++)	mndis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int x=0;x<sta[i].size();x++)
			for(int y=x+1;y<sta[i].size();y++)
			{
				int t=sta[i][x].second+sta[i][y].second,u=sta[i][x].first,v=sta[i][y].first;
				if(t<mndis[u][v])	mndis[u][v]=mndis[v][u]=t;
			}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(mndis[i][j]!=inf)	g[i].push_back({j,mndis[i][j]}),g[j].push_back({i,mndis[i][j]});
//	for(int i=1;i<=n;i++)	dij(i);
	floyd();
	while(q--)
	{
		int x,y,ans=inf;
		cin>>x>>y;
		for(PII l1:sta[x])
			for(PII l2:sta[y])
				ans=min(ans,l1.second+l2.second+mndis[l1.first][l2.first]+w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
30min think
20min write
20min debug	:(
1h10min total
O(md^2+n^3+md^2) 100pts
floyd runs faster than n times dij
:)
*/
