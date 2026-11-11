#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
using namespace std;
int k[505],w[500005];
pair<int,int> v[500005][25];
int cnt[500005];
int dis[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			v[a][++cnt[a]]={i,t};
		}
	}
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500;j++)
			if(i!=j) dis[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=cnt[i];j++)
			for(int k=j+1;k<=cnt[i];k++)
			{
				int x=v[i][j].fir,y=v[i][k].fir;
				dis[x][y]=min(dis[x][y],v[i][j].sec+v[i][k].sec);
				dis[y][x]=dis[x][y];
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=i+1;k<=n;k++)
			{
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
				dis[k][j]=dis[j][k];
			}
	while(q--)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++)
			for(int j=1;j<=cnt[y];j++)
				ans=min(ans,w[x]+w[y]+dis[v[x][i].fir][v[y][j].fir]
				+v[x][i].sec+v[y][j].sec);
		cout<<ans<<"\n";
	}
	return 0;
}
