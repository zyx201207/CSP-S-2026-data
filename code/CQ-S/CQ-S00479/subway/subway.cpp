#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
const ll inf=1e18;
int cid,n,m,d,Q,w[M];
ll val[N][N];
vector<pair<int,int>>g[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cid>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1,j;i<=n;i++)
	{
		cin>>j;
		while(j--)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			val[i][j]=inf;
		}
		val[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			int u=g[i][j].first,w1=g[i][j].second;
			for(int k=j+1;k<g[i].size();k++)
			{
				int v=g[i][k].first,w2=g[i][k].second;
				val[u][v]=val[v][u]=min(val[u][v],(ll)w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k=1;k<=n;k++)
			{
				if(i==k||j==k)continue;
				val[j][k]=val[k][j]=min(val[k][j],val[j][i]+val[i][k]);
			}
		}
	}
	while(Q--)
	{
		int u,v;
		ll ans=inf;
		cin>>u>>v;
		for(auto i:g[u])
		{
			int x=i.first,w1=i.second;
			for(auto j:g[v])
			{
				int y=j.first,w2=j.second;
				ans=min(ans,val[x][y]+w1+w2+w[u]+w[v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
