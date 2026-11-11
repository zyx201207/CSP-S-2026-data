#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005];
int dp[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	dp[0] = 0x7fffffff;
	for(int i=0;i<n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j] = max(dp[j], dp[j-1] & a[i]);
		}
	}
	cout<<dp[m];
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


