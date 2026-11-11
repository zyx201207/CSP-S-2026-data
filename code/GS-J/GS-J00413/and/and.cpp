#include<bits/stdc++.h>
using namespace std;
long long  n,m,ans;
const long long MAXN = 1e9;
long long a[MAXN+5],dp[MAXN][MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			
			dp[i][j] = max(a[i]&a[i-1],dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
