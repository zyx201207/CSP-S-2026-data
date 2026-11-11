#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF=1e9;
ll c,n,m,d,q;
ll M;
ll w[500010];
ll a[1000][1000];
ll k[1000][1000];
ll dist[1000][1000];
ll u,v;
int main()
{
	freopen("subway5.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			dist[i][j]=INF;
			k[i][j]=INF;
		}
	}
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>M;
		for(ll j=1;j<=M;j++)
		{
			cin>>a[i][j]>>k[i][j];
		}
		for(ll j=1;j<M;j++)
		{
			int m=a[i][j];
			if(m==i)
			{
				dist[m][m]=k[m][m];
				continue;
			}
			dist[a[i][j]][a[i][j+1]]=k[i][j+1];
		}
	}		
	
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			for(ll kk=1;kk<=m;kk++)
			{
				dist[i][j]=min(dist[i][j],dist[i][kk]+dist[kk][j]);
			}
		}
	}

	for(ll i=1;i<=q;i++)
	{
		cin>>u>>v;
		cout<<dist[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}

