#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],dp[10002][10002],max1;
bool b[200002];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	max1=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[1][i]=a[i];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			memset(b,0,sizeof(b));
			for(int k=1;k<=n;k++)
			{
				if(b[k]==1)continue;
				if(k==j)continue;
				dp[i][j]=max(dp[i-1][j]&a[k],dp[i][j]);
				b[k]=1;
				if(dp[i][j]>=max1)
				{
					max1=dp[i][j];
				}
			}
		}
	}
	cout<<max1;
	return 0;
}
