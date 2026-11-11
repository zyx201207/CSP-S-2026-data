#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
const int N=510,M=5e5+10,inf=1e18;
int w[M];
vector<PII>G[M],vec[N];
int d[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int C,n,m,D,q;cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,dis;cin>>x>>dis;
			G[x].push_back({i,dis});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(auto p1:G[i])
			for(auto p2:G[i])
				if(p1.fi!=p2.fi)
				{
					int x=p1.fi,y=p2.fi;
					d[x][y]=min(d[x][y],p1.se+p2.se);
					d[y][x]=min(d[y][x],p1.se+p2.se);
				}
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<d[i][j]<<' ';cout<<'\n';}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&i!=k)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--)
	{
		int x,y;cin>>x>>y;
		int ans=inf;
		for(auto p1:G[x])for(auto p2:G[y])
		{
//			cout<<p1.fi<<' '<<p2.fi<<'\n';
			ans=min(ans,w[x]+w[y]+p1.se+p2.se+d[p1.fi][p2.fi]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//Òª¿¨³£ 
