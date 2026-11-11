#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m;
long long a[N],dp[N][N];//前i个数中选了j个的最大值 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1][1]=a[1]; 
	long long maxx=-1e9;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,a[i]);
		dp[i][1]=maxx;
	}
	for(int i=2;i<=n;i++)
		for(int j=min(i,m);j>=2;j--)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		}
	cout<<dp[n][m];
	return 0;
}
