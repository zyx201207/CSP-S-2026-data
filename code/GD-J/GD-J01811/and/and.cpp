#include <bits/stdc++.h>

using namespace std;
const int N=2e3+10;

long long n,m;

long long a[N];
long long sq[25];


long long dp[N][N];




int main()
{


	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{

		cin>>a[i];
		//change(a[i],i);


	}

	if(n>2000)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	//

	for(int i=1;i<=n;i++)
	{

		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++)
	{

		for(int j=1;j<=m;j++)
		{

			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]&a[i]);

		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
