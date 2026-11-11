#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], ans, n, m;
void dfs(int pos, int sum, int tot)
{
	if (tot == m)
	{
		ans = max(ans, sum);
		return;
	}
	if (pos > n) return;
	for (int i = pos + 1; i <= n; i++)
		dfs(i, sum & a[i], tot + 1);
}
inline int read()
{
	char x = getchar_unlocked();
	int res = 0;
	while (x > '9' || x < '0') x = getchar_unlocked();
	while (x >= '0' && x <= '9')
	{
		(res *= 10) += (x - '0');
		x = getchar_unlocked();
	}
	return res;
}
int main()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		dfs(i, a[i], 1);
	printf("%d\n", ans);
	return 0;
}
