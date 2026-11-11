#include <bits/stdc++.h>
#define ll long long
using namespace std;
int C,n,m,d,q;
ll w[500010];
int k[510];
vector<pair<int,ll> >b[500010];
ll dist[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x; ll y; cin>>x>>y;
			b[x].emplace_back(i,y);
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=b[i].size();
		for(int j=0;j<len;j++)
		{
			int u=b[i][j].first;
			ll d1=b[i][j].second;
			for(int k=j+1;k<len;k++)
			{
				int v=b[i][k].first;
				ll d2=b[i][k].second;
				dist[u][v]=dist[v][u]=min(dist[u][v],d1+d2);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--)
	{
		ll ans=1e18;
		int x,y; cin>>x>>y;
		int len1=b[x].size(),len2=b[y].size();
		for(int i=0;i<len1;i++)
		{
			int u=b[x][i].first;
			ll d1=b[x][i].second;
			for(int j=0;j<len2;j++)
			{
				int v=b[y][j].first;
				ll d2=b[y][j].second;
				ans=min(ans,w[x]+w[y]+d1+d2+dist[u][v]);
			}
		}
		cout<<ans<<'\n';
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
