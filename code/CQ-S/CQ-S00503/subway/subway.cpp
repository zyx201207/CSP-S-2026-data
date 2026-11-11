#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct node
{
	long long v,w;
};
int c,n,m,d,q,w[500005];
long long dp[505][505];
vector<node> g[500005];
void Floyd()
{
	for (int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (dp[i][k]==LLONG_MAX || dp[k][j]==LLONG_MAX)
				{
					continue;
				}
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for (int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			dp[i][j]=LLONG_MAX;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (node k1:g[i])
		{
			for (node k2:g[i])
			{
				if (k1.v!=k2.v)
				{
					dp[k1.v][k2.v]=dp[k2.v][k1.v]=k1.w+k2.w;
				}
			}
		}
	}
	Floyd();
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=LLONG_MAX;
		for (node k1:g[x])
		{
			for (node k2:g[y])
			{
				if (dp[k1.v][k2.v]==LLONG_MAX)
				{
					continue;
				}
				ans=min(ans,w[x]+w[y]+k1.w+k2.w+dp[k1.v][k2.v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
