#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],dp[N];
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
		for(int j=m;j>=2;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
		dp[1]=max(dp[1],a[i]);
	}
	cout<<dp[m];
	return 0;
}
