#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;
long long n, m, maxn, a[MAXN];
bool vis[MAXN];

void dfs(long long x, long long k, long long j)
{
	long long num = x;
	if (j != 0) maxn = max(x, maxn);
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			if (k == m)
			{
				num = a[i];
				vis[i] = 1;
				dfs(num, k - 1, j);
				vis[i] = 0;
				num = x;
			}
			else
			{
				num &= a[i];
				vis[i] = 1;
				dfs(num, k - 1, j + 1);
				vis[i] = 0;
				num = x;
			}
		}
	}
	if (k == 0) return;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(0, m, 0);
	cout << maxn;
	return 0;
}
