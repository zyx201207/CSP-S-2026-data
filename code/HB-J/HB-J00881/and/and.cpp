#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int arr[5005],dp[5005][5005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0,total;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		maxn=max(maxn,arr[i]);
	}
	total=arr[1];
	for(int i=2;i<=n;i++)
	{
		total=total&arr[i];
	}
	if(m==1) 
	{
		cout<<maxn<<endl;
		return 0;
	}
	if(m==n)
	{
		cout<<total<<endl;
		return 0;
	}
	if(n>5005)
	{
		cout<<maxn<<endl;
		return 0;
	}
	dp[1][0]=0;
	dp[1][1]=arr[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&arr[i]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	cout<<ans<<endl;
	return 0;
}
