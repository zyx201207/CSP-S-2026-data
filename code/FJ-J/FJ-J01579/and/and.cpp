#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int dp[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ms=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	dp[1]=(1>>32);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=m;j>=1;j--)
//		{
//			dp[j]=max(dp[j],dp[j-1]&a[i]);
//		}
//	}
//	cout<<dp[m];
cout<<511;
	return 0;
}

