#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], ans;
void dfs(int f, int i, int sum)
{
	if (f > m)
	{
		ans = max(ans, sum);
		return;
	}
	for (int j = i; j <= n-(m-f); j++)
	{
		dfs(f+1, j+1, sum & a[j]);
	}
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
	for (int i = 1; i <= n-m+1; i++)
	{
		dfs(2, i+1, a[i]);
	}
	cout << ans;
	return 0;
}
