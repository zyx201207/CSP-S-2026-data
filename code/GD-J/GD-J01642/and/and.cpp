#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
long long n, m, a[N], ans;
void dfs(long long num, long long cnt, long long d)
{
	if (cnt == m)
	{
		ans = max(ans, d);
		return;
	}
	if (num > n)
	{
		if (cnt == m)
			ans = max(ans, d);
		return;
	}
	if (d == -1)
	{
		dfs(num + 1, cnt + 1, a[num]);
		dfs(num + 1, cnt, -1);
	}
	else
	{
		dfs(num + 1, cnt + 1, d & a[num]);
		dfs(num + 1, cnt, d);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, -1);
	cout << ans;
	return 0;
}
