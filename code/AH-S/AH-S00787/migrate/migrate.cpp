#include<bits/stdc++.h>
using namespace std;
long long dp[2000001],dp2[2000001],a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t;
	cin>>t>>t;
	while(t--)
	{
		long long n,d,sum=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++)
		{
			memset(dp,0,sizeof dp);
			memset(dp2,0x3f3f3f3f,sizeof dp2);
			dp[i]=1;
			dp2[i]=1;
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j-1;k>=i;k--)
				{
					if(a[j]-a[k]>d) break;
					if(dp2[k]+1<dp2[j]) dp[j]=1,dp2[j]=dp2[k]+1;
					else dp[j]++;
				}
				if(dp[j]==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
