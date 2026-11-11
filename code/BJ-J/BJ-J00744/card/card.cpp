#include <iostream>
using namespace std;

int n, m, a[500005], ans[300005], t[500005], cnt[300005];
bool A = true;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] < a[i - 1]) A = false;
	}
	if (m == 1)
	{
		cout << n << '\n';
		return 0;
	}
	if (m == 2)
	{
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1 && a[n] == 1) ++cnt1;
			else if (a[i] != a[n]) ++cnt1, ++cnt2;
			else if (a[i] == 2 && a[n] == 2) ++cnt2;
		cout << cnt1 << ' ' << cnt2 << '\n';
		return 0;
	}
	if (A)
	{
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			++sum;
			if (a[i] != a[i + 1]) cout << sum << ' ';
		}
		return 0;
	}
	for (int z = 1; z <= n; ++z)
	{
		for (int i = z; i <= n; ++i) t[i] = a[i];
		for (int i = 1; i <= m; ++i) cnt[i] = 0;
		for (int i = z; i <= n; ++i)
		{
			if (cnt[t[i]])
			{
				int j = i - 1;
				while (j > z && t[j] != t[i]) --cnt[t[j]], t[j] = 0, --j;
				--cnt[t[j]], t[j] = 0;
			}
			++cnt[t[i]];
		}
		for (int i = z; i <= n; ++i) ++ans[t[i]];
	}
	for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
	return 0;
}