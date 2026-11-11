#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],maxn=-1e18;
int dp[2][N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[0][0]=dp[1][0]=(1<<31)-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(n,m);j++)
		{
			dp[i&1][j]=max(dp[(i-1)%2][j],dp[(i-1)%2][j-1]&a[i]);
		}
		if(i>=m)maxn=max(maxn,dp[i&1][m]);
	}
	cout<<maxn;
	return 0;
}
