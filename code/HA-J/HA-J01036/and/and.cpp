#include <bits/stdc++.h>
using namespace std;
int n, m, maxand, a[200005];
void dfs(int now_and, int now_count, int now_i)
{
	if (now_count == m)
	{
		maxand = max(now_and, maxand);
	}
	for (int i = now_i; i <= n; i++)
	{
		dfs(now_and & a[i], now_count + 1, i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			maxand = max(maxand, a[i]);
		}
	} 
	else if (m == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				maxand = max(maxand, a[i] & a[j]);
			}
		}
	}
	else
	{
		dfs(0, 0, 1);
	}
	cout << maxand << "\n";
	
	return 0;
} 
