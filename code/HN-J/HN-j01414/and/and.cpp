#include<bits/stdc++.h>
using namespace std;

int ux;

int n,m;
long long a[200066];
long long dp[200066];

void why_dp()
{
	fill(dp+1,dp+m+1,-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=2;j--)
		{
			if(dp[j-1]>=0)
			{
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
		}
		dp[1]=max(dp[1],a[i]);
	}
	return;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ux=scanf("%d%d",&n,&m);
	if(ux!=2) return 1;
	for(int i=1;i<=n;i++)
	{
		ux=scanf("%lld",&a[i]);
		if(ux!=1) return 2;
	}
	why_dp();
	printf("%lld",dp[m]);
	return 0;
} 
/*
5 3
31 3 1 15 7
*/
