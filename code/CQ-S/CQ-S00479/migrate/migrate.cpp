#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,inf=1e18;
int cid,n,a[N],d,dp[N][N],cnt[N][N],ans;
void solve()
{
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=inf;
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			for(int i=l;i<r;i++)
			{
				if(a[r]-a[i]<=d)
				{
					if(dp[l][i]+1<dp[l][r])
					{
						dp[l][r]=dp[l][i]+1;
						cnt[l][r]=cnt[l][i];
					}
					else if(dp[l][r]==dp[l][i]+1)cnt[l][r]+=cnt[l][i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(cnt[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=cnt[i][j]=0;
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>cid>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
