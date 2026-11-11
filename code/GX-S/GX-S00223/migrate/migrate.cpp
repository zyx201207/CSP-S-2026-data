#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll len, n, d, ans, a[N], x[N], lst[N], pre[N], l[N], r[N];
ll f[N], g[N], sum[N];
void solve(int L, int R)
{
	n = R - L + 1;
	for (int i = L; i <= R; i++)
		a[i - L + 1] = x[i];
	for (int i = 1; i <= n; i++)
		lst[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
	for (int i = 1; i <= n; i++)
		pre[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
	f[1] = g[n] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = 1;
		if (pre[i - 1] == i)
			f[i] += f[i - 1];
	}
	for (int i = n - 1; i; i--)
	{
		g[i] = 1;
		if (lst[i + 1] == i)
			g[i] += g[i + 1];
	}
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + g[i];
	l[n] = r[n] = 0;
	for (int i = 1, l, r; i < n; i++)
	{
		if (pre[i] == i + 1)
			l = r = 0;
		else if (pre[i] == i + 2)
		{
			l = pre[i] + 1;
			r = pre[pre[i] - 1];
		}
		else
		{
			l = pre[pre[i] - 2] + 1;
			r = pre[pre[i] - 1];
		}
		if (l && l <= r)
			ans += f[i] * (sum[r] - sum[l - 1]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t;
	cin >> t >> t;
	while (t--)
	{
		ans = 0;
		cin >> len >> d;
		for (int i = 1; i <= len; i++)
			cin >> x[i];
		for (int lst = 1, i = 2; i <= len; i++)
		{
			if (x[i] - x[i - 1] > d)
				solve(lst, i - 1), lst = i;
			if (i == len)
				solve(lst, i);
		}
		cout << ans << endl;
	}
	return 0;
}