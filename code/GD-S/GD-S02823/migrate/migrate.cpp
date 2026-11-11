#include<bits/stdc++.h>
using namespace std;
long long c,u,a,k,t[2000000],dp[2000000],sum[200000];
int main()
{
	scanf("%lld%lld",&c,&u);
	for(int i=1;i<=u;i++)
	{
		scanf("%lld%lld",&a,&k);
		for(int j=1;j<=a;j++)
			scanf("%lld",&t[j]);
		dp[1]=0;
		for(int j=1;j<=a-1;j++)
		{
			for(int c=j+1;c<=a;c++)
				if(t[c]-t[j]<=k) dp[c]++;
		}
		for(int j=1;j<=a;j++)
		{
			if(dp[j]==2) sum[i]++;
			dp[j]=0;
		}
	}
	for(int i=1;i<=u;i++)
		cout<<sum[i]-1<<endl;
	return 0;
}
