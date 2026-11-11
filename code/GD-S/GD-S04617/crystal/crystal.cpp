#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 100;

int ans = -INT_MAX;
int vis = 1;
int n, m;

int tong[N];
int cha[N];
int d[N];
int r[N];

int dp[6000][6000];

int main() 
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	memset(dp, 0x3f, sizeof(dp));
	
	for (int i = 1; i <= n; i ++ ) 
	{
		cin >> r[i];
	}
	
	sort(r + 1, r + n + 1);
	
	cha[1] = r[2] - r[1];
	for (int i = 2; i < n; i ++ ) 
	{
		cha[i] = r[i + 1] - r[i];
		d[i] = cha[i] + r[i - 1];
		if (cha[i] != cha[i - 1]) 
		{
			vis = 0;
		}
	}
	
	if (vis == 1) 
	{
		int d = cha[1];
		for (int res = 1; res <= n; res ++ ) 
		{
			double num = (1.0 * res * (res + 1) * d) / 2;
			if (num == 1.0 * m) 
			{
				cout << res + 1;
				return 0;
			}
			else if (num > 1.0 * m) 
			{
				cout << res;
				return 0;
			}
		}
	}
	 
	else 
	{
		for (int i = 1; i <= n; i ++ ) 
		{
			dp[i][i] = 0;
		}
		
		for (int len = 1; len <= n; len ++ ) 
		{
			for (int i = 1;i < n; i ++ ) 
			{
				int j = len + i - 1;
				for (int k = i; k < j; k ++ ) 
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[j] - d[i - 1]);
					if (dp[i][j] == m) 
					{
						cout << len;
						return 0;
					}
					if (dp[i][j] > m) 
					{
						cout << len + 1;
						return 0;
					}
				}
			}
		}
	}
}
