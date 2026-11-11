#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[500010], sum;
long long dp[10001][10001];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if(n>10000)
	{
		int a, b, c;
		cin >> a >> b;
		c = b - a;
		while(m >= sum*c)
		{
			m -= sum*c;
			sum++;
		}
		cout << sum + 1;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		dp[i][i] = 0;
	}
	sort(a+1, a+n+1);
	
	for(int t = 2; t <= n; t++)
	{
		for(int i = 1; i + t - 1 <= n; i++)
		{
			int j = i + t - 1;
			dp[i][j] = (a[j]-a[j-1])*(t-1)+dp[i][j-1];
			if(dp[i][j]<=m)
			{
				sum = t;
			}
		}
	}
	cout << sum;
	return 0;
}
