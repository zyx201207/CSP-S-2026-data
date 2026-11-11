#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		long long n,d;
		long long a[10005];
		long long dp[205][205];
		long long sum[205][205];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		 } 
		 for(int i=1;i<=n;i++)
		 {
		 	for(int j=1;j<i;j++)
		 	{
		 		if(a[i]-a[j]<=d)
		 		{
		 			sum[j][i]=1;
		 			continue;
				 }
		 		for(int k=j+1;k<i;k++)
		 		{
		 			if(a[i]-a[k]<=d)
		 			{
		 				sum[j][i]=sum[j][k]+1;
					 }
			  }
				 sum[j][i]=max(sum[j][i],1ll);
			 }
		 }
		 for(int i=1;i<=n;i++)
		 {
		 	for(int j=1;j<=n;j++)
		 	{
		 		if(i==j)
		 		{
		 			continue;
				 }
				 for(int k=i+1;k<j;k++)
				 {
				 	if(sum[i][k]+sum[k][j]==sum[i][j])
				 	{
				 		dp[i][j]++;
					 }
				 }
				 if(dp[i][j]==2)
				 {
				 	ans++;
				 }
			 }
		 }
		cout<<ans<<"\n";
	}
	return 0;
}
