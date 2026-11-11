#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int dp[N],n,m,a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j==1)dp[j]=a[i];
			else dp[j]=max(dp[i-1],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;	
} 
