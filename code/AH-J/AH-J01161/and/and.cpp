#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			long long b=a[i];
			dp[j]=max(dp[j-1]&a[i],b);
		}
	}
	cout<<dp[m];
	return 0;
}
