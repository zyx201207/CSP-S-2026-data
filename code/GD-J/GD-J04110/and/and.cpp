#include <bits/stdc++.h>
using namespace std; 

int n, m; 
long long a[200005], dp[200005][200005]; //dp[i][j] 表示 前 i 个数 中 选 j 个的最大值 i <= m，j <= n，i <= j 

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	//freopen("and.in", "r", stdin); 
	//freopen("and.out", "w", stdout); 
	
	cin >> n >> m; 
	
	
	
	long long mx = 0; 
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		mx = max(mx, a[i]);  
		dp[1][i] = mx; 
	}
	cout << mx; 
	/*
	for (int i = 2; i <= n; i++)
	{
		dp[i][i] = dp[i-1][i-1]; 
		for (int j = 1; j <= i && j <= m; j++)
		{
			for (int k = 1; k <= i-1; k++)
			{
				dp[i][j] = max(dp[i-1][k] & a[j], dp[i][j]); 
			}
		}
	}
	cout << dp[n][m]; 
	*/
}
