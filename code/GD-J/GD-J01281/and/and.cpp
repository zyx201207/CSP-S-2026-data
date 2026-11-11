#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int dp[N][N];
int a[N];
int main()
{
	 int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 cin>>n>>m;
	 cin>>a[1];
	 dp[1][1]=a[1];
	 for(int i=2;i<=n;i++)
	 {
	 	cin>>a[i];
	 	dp[i][1]=max(dp[i-1][1],a[i]);
	}
	 for(int i=2;i<=n;i++)
	 {
	 	for(int j=2;j<=i;j++)
	 	{
	 		dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
		 }
	 }
	 cout<<dp[n][m];
	 return 0;
}
