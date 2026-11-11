#include <bits/stdc++.h> 
using namespace std;
long long a[500005];
long long d[500005];
long long s[500005];
long long dp[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	d[0]=max((long long)0,a[0]);
	for(long long i=1;i<n;i++) 
		d[i]=a[i]-a[i-1];
	for(long long i=0;i<n;i++) 
		s[i]=d[i]+s[i-1];
	long long sum=0,maxx=0;
	for(int i=0;i<n;i++)
	{
		dp[i]=max(d[i]+dp[i-1],dp[i]);
		if(dp[i]>m)
		{
			maxx=max(maxx,sum);
			sum=0,dp[i]=0;
		}
		sum++;
	}
//	for(int i=0;i<n;i++)
//		cout<<dp[i]<<" ";
	cout<<max(maxx,sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5  
1 2 4 8 9

*/
//493662534
//293238795
