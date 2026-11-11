#include<bits/stdc++.h>
using namespace std;
long long dp[200005],a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,m);j>=1;j--)
		{
			if(j==0)continue;
			if(j==1)dp[1]=max(dp[1],a[i]);
			else
			{
				if(i>j)dp[j]=dp[j];
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
			//cout<<dp[i][j]<<" "<<a[i]<<" "<<j<<endl;
		}
	}
	cout<<dp[m];
	return 0;
}
