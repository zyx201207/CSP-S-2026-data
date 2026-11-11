#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
const int N=2e6+5;
const int inf=2e18+5;
int c,t,n,d,a[N],dp[5005][5005],g[5005][5005];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=inf;
			dp[i][i]=0;
			g[i][i]=1;
			g[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j-1;k++)
			{
				if(a[j]-a[k]>d) continue;
				int dis=dp[i][k]+1;
				if(dis<dp[i][j]) g[i][j]=g[i][k];
				else if(dis==dp[i][j]) g[i][j]+=g[i][k];
				dp[i][j]=min(dp[i][j],dis);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(g[i][j]==2) res++;
		}
	}
	cout<<res<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	faster;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}