#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 10, M = 2005;
int a[N], dp[M], n, m, maxn, c[N];
void dfs(int step, int sum)
{
	if (step == m)
	{
		maxn = max(maxn, sum);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(step+1, sum+a[i]&a[i-1]);
	}
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 2000 && m == 1)
	{	
		int maxx = 0;
		for (int i = 1; i <= n; i++) maxx = max(maxx, a[i]);
		cout << maxx << endl;
		return 0;
	}
	else if (n <= 2000 && m == n)
	{
		int ans = a[1];
		for (int i = 2; i <= n; i++)
		{
			ans &= a[i];
		}
		cout << ans << endl;
		return 0;
	}
	else if (n <= 2000 && m == 2)
	{
		int maxx = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				if (j == i) continue;
				int t = a[i] & a[j];
				maxx = max(maxx, t); 
			} 
		}
		cout << maxx << endl;
		return 0;
	} 
	dfs(1,0);
	cout << maxn << endl;
	return 0;
}
