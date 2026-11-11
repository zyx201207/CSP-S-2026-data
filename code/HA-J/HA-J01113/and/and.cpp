#include <bits/stdc++.h>
using namespace std;
long long a[20005],dp[20005],vis[20005],qwe;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],vis[1]=1,dp[1]=max(dp[1],a[i]);
	if(m==1) {cout<<dp[1];return 0;}   
	//for(int i=1;i<=n;i++) dp[i]=dp[1];
	qwe=a[1];
	for(int i=2;i<=n;i++) {qwe&=a[i];}
	if(n==m) {cout<<qwe;return 0;}
	for(int i=2;i<=n;i++)
	{
		for(int j=m;j>=2;j--)
		{
			long long www=dp[j-1];
			www&=a[i];
			if(dp[j]==0&&vis[j]==0) dp[j]=a[i],vis[j]=1;
			if(vis[j]<j) dp[j]=www,vis[j]=vis[j-1]+1;
			else dp[j]=max(dp[j],www);
		}
	}
	cout<<dp[m];
	return 0;
}
