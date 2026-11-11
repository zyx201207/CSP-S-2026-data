#include <algorithm>
#include <iostream>
using namespace std;

long long n, m, a[200005], ans;
bool A = true, N = true;

void dfs(long long step, long long cnt, long long sum)
{
	if (cnt > m) return;
	if (step > n)
	{
		if (cnt == m) ans = max(ans, sum);
		return;
	}
	dfs(step + 1, cnt + 1, sum & a[step]);
	dfs(step + 1, cnt, sum);
}

bool cmp(long long x, long long y)
{
	return x > y;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		bool flag = false;
		long long t = 1;
		for (int j = 1; j <= 31; ++j)
		{
			if (a[i] + 1 == t)
			{
				flag = true;
				break;
			}
			t *= 2;
		}
		if (!flag) A = false;
		if (a[i] > 3) N = false;
	}
	if (n <= 20)
	{
		dfs(1, 0, 2147483647);
		cout << ans << '\n';
		return 0;
	}
	if (m == 1)
	{
		long long maxn = 0;
		for (int i = 1; i <= n; ++i) maxn = max(maxn, a[i]);
		cout << maxn << '\n';
		return 0;
	}
	if (m == 2)
	{
		long long maxn = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (i != j) maxn = max(maxn, a[i] & a[j]);
		cout << maxn << '\n';
		return 0;
	}
	if (m == n)
	{
		long long ans = a[1];
		for (int i = 2; i <= n; ++i) ans &= a[i];
		cout << ans << '\n';
		return 0;
	}
	if (A)
	{
		sort(a + 1, a + n + 1, cmp);
		cout << a[m] << '\n';
		return 0;
	}
	if (N)
	{
		long long cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1) ++cnt1;
			else if (a[i] == 2) ++cnt2;
			else ++cnt3;
		if (cnt3 >= m) cout << 3;
		else if (cnt2 + cnt3 >= m) cout << 2;
		else if (cnt1 + cnt3 >= m) cout << 1;
		else cout << 0;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	for (int i = 2; i <= m; ++i) ans &= a[i];
	cout << ans << '\n';
	return 0;
}