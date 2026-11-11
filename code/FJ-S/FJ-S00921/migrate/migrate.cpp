#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[10000005],ans;
struct node
{
	int m,sum;
} dp[10000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>t;
	for(int i=1;i<=1000000;i++) dp[i].m=1e18,dp[i].sum=0;
	while(t--)
	{
		ans=0;
		cin >>n>>d;
		for(int i=1;i<=n;i++) cin >>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				dp[i].m=0,dp[i].sum=1;
				for(int k=i+1;k<=j;k++)
				{
					for(int l=k-1;l>=i;l--)
					{
						if(a[k]-a[l]<=d)
						{
							if(dp[l].m+1<dp[k].m)
							{
								dp[k].m=dp[l].m+1;
								dp[k].sum=dp[l].sum;
							}
							else if(dp[l].m+1==dp[k].m)
							{
								dp[k].sum+=dp[l].sum;
							}
						}
						else
						{
							break;
						}
					}
				}
				//if(i==1&&j==4) cout <<dp[j].sum<<" ";
				if(dp[j].sum==2) ans++;
				for(int k=i;k<=j;k++) dp[k].m=1e18,dp[k].sum=0;
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}

