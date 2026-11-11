#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int t,n,m,d,q,w[M],dp[N][N];
struct n1
{
	int x,y;
};
vector<n1> e[N];
vector<n1> p[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,0x3f,sizeof dp);
	cin>>t>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			cin>>x>>y;
			e[i].push_back({x,y});
			p[x].push_back({i,y});
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		for(auto x:e[i])
		{
			for(auto y:p[x.x])
			{
				if(y.x==i) continue;
				dp[i][y.x]=min(dp[i][y.x],x.y+y.y);
				// cout<<i<<' '<<y.x<<'\n';
			}
		}
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	// cout<<dp[1][2]<<' ';
	for(int i=1;i<=q;++i)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto j:p[x])
		{
			for(auto k:p[y])
			{
				ans=min(ans,dp[j.x][k.x]+j.y+k.y);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}