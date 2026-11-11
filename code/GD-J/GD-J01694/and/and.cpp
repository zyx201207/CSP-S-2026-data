#include<bits/stdc++.h>
using namespace std;
int dp[200002][2];
int a[200002];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n==m&&a[n]==0)
		return cout<<0,0;
	bool _$,$=0;
	dp[0][0]=dp[0][1]=-1;
	for(int i=1;i<=n;i++)
	{
		_$=$,$=!$;
		const int ai=a[i];
		const int limit=min(i,m);
		for(int j=1;j<=limit;j++)
			dp[j][$]=max(dp[j][_$],dp[j-1][_$]&ai);
	}
	cout<<dp[m][$];
	return 0;
}
