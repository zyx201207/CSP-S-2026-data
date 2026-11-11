#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
const ll INF=1e18;
int c,n,m,d,q;
int w[M];
struct node{int x,w;};
vector<node> vc[M];
ll dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			vc[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vc[i].size();j++)
		{
			for(int k=0;k<vc[i].size();k++)
			{
				int x=vc[i][j].x,y=vc[i][k].x;
				dis[x][y]=min(dis[x][y],(ll)vc[i][j].w+(ll)vc[i][k].w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int j=1;j<=n;j++)
			for(int i=1;i<=n;i++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(int i=0;i<vc[x].size();i++)
		{
			for(int j=0;j<vc[y].size();j++)
			{
				ans=min(ans,dis[vc[x][i].x][vc[y][j].x]+w[x]+w[y]+vc[x][i].w+vc[y][j].w);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
