#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+10,M=510;
using ll = long long;
using pil = pair<int,ll>;
int c,n,m,d,q;
ll w[N],G[M][M];
vector <pil> g[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			G[i][j]=G[j][i]=1e15;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		for(int j=1,a,t;j<=x;j++)
		{
			cin>>a>>t;
			g[a].emplace_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++)
	{
		int siz=g[i].size(),x,y;
		for(int j=0;j<siz;j++)
			for(int k=j+1;k<siz;k++)
			{
				x=g[i][j].first,y=g[i][k].first;
				G[x][y]=min(G[x][y],g[i][j].second+g[i][k].second);
				G[y][x]=min(G[y][x],g[i][j].second+g[i][k].second);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(G[i][k]<1e15 && G[k][j]<1e15)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=1e15;
		for(auto u:g[x])
			for(auto v:g[y])
				ans=min(ans,G[u.first][v.first]+u.second+v.second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
