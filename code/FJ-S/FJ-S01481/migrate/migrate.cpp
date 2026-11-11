#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],dp[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		int ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		memset(dp,0x3f3f3f3f,sizeof(dp));
		dp[1]=x[1],dp[2]=x[2]-x[1];
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				dp[i]=max(dp[j]+x[i]-x[j],dp[i]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int c=0;
				for(int k=i+1;k<=j-1;k++)
				{
					if(dp[k]+x[j]-x[k]==dp[j])
					{
						c++;
						dp[j]=max(dp[k]+x[j]-x[k],dp[j]);
					}
					else if(dp[k]+x[j]-x[k]<dp[j])
					{
						c=1;
						dp[j]=max(dp[k]+x[j]-x[k],dp[j]);
					}
					else
					{
						continue;
					}
				}
				if(c==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
