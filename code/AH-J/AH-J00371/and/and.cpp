#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long arr[N];
long long dp[N];
int f(int n,int m)
{
	if(m == 0) return dp[n - 1];
	for(int i = 0;i < n;i++)
	{
		for(int j = n - 1;j >= i;j--)
		{
			dp[i] = max(dp[i], arr[j]&arr[i]);
		}
	}
	sort(dp, dp + n);
	return f(n, m - 1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	f(n, m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
