#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=2010;
int n,m,dp[N][N],a[N]; 
signed main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		dp[i][1]=max(dp[i-1][1],a[i]);
		for (int j=1;j<=min(n,m);j++)
		{
			dp[i][j]=max(dp[i][j],dp[i-1][j]) ;// 这个数不参与 
			dp[i][j]=max(dp[i][j],(dp[i-1][j-1]&a[i])); 
		}
	}
	cout<<dp[n][m];
	return 0;	
} 
