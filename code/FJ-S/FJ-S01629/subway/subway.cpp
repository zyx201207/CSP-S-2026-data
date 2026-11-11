#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> g[500005];
int t[505][500005];
long long f[505][505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i =1;i<=n;i++)
	{
		int k;
		cin>>k;
//		g2.clear();
		for(int j =1;j<=k;j++)
		{
			int a,tt;
			cin>>a>>tt;
			t[i][a]=tt;
			g[a].push_back(i);
//			for(pii to:g2)
//			{
//				int v=to.first;
//				int w=to.second;
//			}
//			g2.push_back({a,t});
		} 
//		for(pii u:g2)
//		{
//			for(pii v:g2)
//			{
//				if(u.first!=v.first)
//				{
//					g[u.first][v.first]=min(u.second+v.second,g[u.first][v.first]);
//				}
//			}
//		}
	}
	memset(f,0x3f,sizeof f);
	for(int i =1;i<=n;i++) f[i][i]=0ll;
	for(int i =1;i<=m;i++)
	{
		for(int u:g[i])
		{
			for(int v:g[i])
			{
				f[u][v]=f[v][u]=min(f[u][v],(1ll*t[u][i]+1ll*t[v][i]));
			}
		}
	}
	for(int k =1;k<=n;k++)
	{
		for(int i =1;i<=n;i++)
		{
			for(int j =1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i =1;i<=n;i++)
//	{
//		for(int j =1;j<=n;j++) cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(int k =1;k<=m;k++)
//	{
//		for(int i =1;i<=m;i++)
//		{
//			for(int j =1;j<=m;j++)
//			{
//				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//			}
//		}
//	}
	while(q--)
	{
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(int u:g[x])
		{
			for(int v:g[y])
			{
				if(t[u][x]==0||t[v][y]==0) continue;
				ans=min(ans,1ll*t[u][x]+1ll*t[v][y]+f[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
