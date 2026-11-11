#include<bits/stdc++.h>
using namespace std;
int c,t,a[5005],dp[5005][3],ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		scanf(" %d %d",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)
			scanf(" %d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int k=j-1;
				dp[j][2]=1e9;
				dp[i][1]=0;
				dp[i][2]=0;
				dp[i+1][1]=1;
				dp[i+1][2]=1;
				while(a[j]-a[k]<=d&&k>=1)
				{
					if(dp[j][2]>dp[k][2]+1)
					{
						dp[j][2]=dp[k][2]+1;
						dp[j][1]=max(1,dp[k][1]);
					}
					else if(dp[j][2]==dp[k][2]+1)
					dp[j][1]+=dp[k][1];
					k--;
				}
				if(dp[j][1]==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
