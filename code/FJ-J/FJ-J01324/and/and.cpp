#include <bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int main()
{
	
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	long long n,m;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=a[i];
		
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>0;j--)
		{
			dp[j]=max(dp[j]&a[j-1],dp[j-1]&a[j]);
		}
	}
	cout<<dp[n];
	return 0;
	
	
	
	
	
}
