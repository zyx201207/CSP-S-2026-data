#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2;
const int M=5e5;
struct st
{
	int to;ll ti;
};
int c,n,m,d,q,k,to,x,y;
ll w[M+5],dis[N+5][N+5],t,ans;
vector<st>e[M+5];
void solve()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++) cin>>to>>t,e[to].push_back({i,t});
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			for(int k=0;k<e[i].size();k++)
			{
				int u=e[i][j].to,v=e[i][k].to;
				dis[u][v]=min(dis[u][v],e[i][j].ti+e[i][k].ti);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		cin>>x>>y;ans=1e18;
		for(int j=0;j<e[x].size();j++)
		{
			for(int k=0;k<e[y].size();k++)
			{
				int u=e[x][j].to,v=e[y][k].to;
				ans=min(ans,dis[u][v]+e[x][j].ti+e[y][k].ti);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;//cin>>_;
	while(_--) solve();
	return 0;
}
