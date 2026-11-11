#include<iostream>
#include<cmath>
using namespace std;
int n,m;
long long a[100];
long long dp[100][100];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long maxn=-1;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
//		maxn=max(maxn,a[i]);
		dp[i][1]=a[i];
		dp[0][i]=a[i];
//		dp[1][i]=a[i];
	}
//	for(int i=1; i<=n; i++)
//	{
//		for(int j=1; j<=m; j++)
//		{
//			cout<<dp[i][j];
//		}
//		cout<<endl;
//	}w
	dp[0][0]=a[1];
	dp[0][1]=a[1];
	dp[1][0]=a[1];
	dp[1][1]=a[1];
//	cout<<(12&15)<<"**";
	for(int i=1; i<=n; i++)//qian i ge
	{
		for(int j=m; j>=1; j--)//xuan ji ge
		{
			dp[i][j]=max((dp[i-1][j-1]&a[i]),dp[i-1][j]);
		}
	}
	cout<<dp[n][m];
	return 0;
}
