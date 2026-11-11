#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=514,M=1e6;
int C,n,m,d,q;
ll w[M],dis[N][N];
std::vector<std::pair<int,ll>> L[M];

int main()
{
	fr(subway)
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int a,t;k--;)
		{
			cin>>a>>t;
			L[a].emplace_back(i,ll(t));
		}
	}
	std::fill(dis[0],dis[n+1],ll(4e18));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<L[i].size();j++)
		{
			for(int k=j+1;k<L[i].size();k++)
			{
				int u=L[i][j].first;ll x=L[i][j].second;
				int v=L[i][k].first;ll y=L[i][k].second;
				dis[u][v]=std::min(dis[u][v],x+y);
				dis[v][u]=std::min(dis[v][u],x+y);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int x,y;q--;)
	{
		cin>>x>>y;
		ll ans=4e18;
		for(int j=0;j<L[x].size();j++)
		{
			for(int k=0;k<L[y].size();k++)
			{
				int u=L[x][j].first;ll uw=L[x][j].second;
				int v=L[y][k].first;ll vw=L[y][k].second;
				ans=std::min(ans,uw+dis[u][v]+vw);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
		// fprintf(stderr,"%lld\n",ans);
	}
	return 0;
}
