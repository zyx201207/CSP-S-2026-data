#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+1e1,M=5e5+1e2;
int c,d,q,n,m,w[M],dis[N][N];
vector<int>t[M],id[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=0;j<k;j++)
		{
			int x,y; cin>>x>>y;
			t[x].push_back(y);
			id[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=id[i].size();
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++)
			{
				int x=id[i][j],y=id[i][k];
				dis[x][y]=min(dis[x][y],t[i][j]+t[i][k]);
				dis[y][x]=min(dis[y][x],t[i][j]+t[i][k]);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int u,v,ans=1e18;
		cin>>u>>v;
		for(int i=0;i<id[u].size();i++)
			for(int j=0;j<id[v].size();j++)
			{
				int x=id[u][i],y=id[v][j];
				ans=min(ans,w[u]+w[v]+t[u][i]+t[v][j]+dis[x][y]);
			}
		cout<<ans<<'\n';
	}
}