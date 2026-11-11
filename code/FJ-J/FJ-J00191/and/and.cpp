#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],dp[N][2030]={},ans=INT_MIN;
int main()
{
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=a[i];
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				dp[j][k]=max(dp[j][k],dp[j-1][k-1]&a[j]); 
			}
		}
		ans=max(ans,dp[i][m]);
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	cout<<ans;
	return 0;
}
