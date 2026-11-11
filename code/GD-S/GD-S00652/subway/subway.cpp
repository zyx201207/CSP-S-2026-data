#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510,M=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
pair<ll,ll> e[M][20];
ll dis[N][N],w[M],f[M];
ll c,n,m,d,q;
void Floyd()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;i++)
		for(int j=0;j<f[i];j++)
			for(int k=j+1;k<f[i];k++)
				dis[e[i][j].first][e[i][k].first]=min(dis[e[i][j].first][e[i][k].first],e[i][j].second+e[i][k].second);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main()
{
	freopen("subway2.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q; ll x,y,z;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>z;
		while(z--) cin>>x>>y,e[x][f[x]++]={i,y};
	}
	while(q--)
	{
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<f[x];i++)
			for(int j=0;j<f[y];j++)
				ans=min(ans,e[x][i].second+e[y][j].second+min(dis[e[x][i].first][e[y][j].first],dis[e[y][j].first][e[x][i].first]));
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
1 2 3 4 5 6 7 8 
*/
