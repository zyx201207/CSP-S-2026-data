#include<bits/stdc++.h>
#define pi pair<int,int>
#define fi first
#define se second
#define mk make_pair 
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
const ll inf=1e18;
vector<pi> b[N],c[M];
ll dis[M][M];
int w[N],n,m; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _,__,q;
	cin>>_>>n>>m>>__>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,t;
			cin>>a>>t;
			c[i].push_back(mk(a,t)),b[a].push_back(mk(i,t));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:inf);
	}
	for(int i=1;i<=n;i++)
	{
		for(pi u:c[i])
		{
			for(pi v:b[u.fi])
			{
				dis[i][v.fi]=min(dis[i][v.fi],(ll)u.se+v.se);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(pi u:b[x])
			for(pi v:b[y])
				ans=min(ans,dis[u.fi][v.fi]+u.se+v.se);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
