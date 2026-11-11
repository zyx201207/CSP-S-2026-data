#include<bits/stdc++.h>
// at 16:20
#define N 500005
#define M 505
using namespace std;
typedef long long ll;

int typ,n,m,d,q;
vector<pair<int,ll> > g[N];
ll tt[N],dis[M][M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>typ>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>tt[i];
	for(int i=1,k,v,w;i<=m;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>v>>w;
			g[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++)
	{
		for(auto j:g[i])
		{
			for(auto k:g[i])
			{
				if(j.first!=k.first)
				{
					ll w=j.second+k.second;
					dis[j.first][k.first]=dis[k.first][j.first]=min(dis[k.first][j.first],w);
				}
			}
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=m;i++)dis[i][i]=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll sum=tt[x]+tt[y],ans=1e18;
		for(auto i:g[x])
			for(auto j:g[y])
				ans=min(ans,sum+dis[i.first][j.first]+i.second+j.second);
		cout<<ans<<'\n';
	}
	return 0;
}