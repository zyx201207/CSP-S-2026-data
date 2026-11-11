#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], b[N], s[N], lbs[N], n, m;
int query(int l,int r)
{
	int len = r - l + 1;
	return s[r] * len - lbs[r] + lbs[l - 1];
}
bool chk(int mid)
{
	for (int i = 1;i + mid - 1 <= n;i++)
	{
		if (query(i, i + mid - 1) <= m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) b[i] = a[i] - a[i - 1], s[i] = s[i - 1] + b[i];
	for (int i = 1;i <= n;i++) lbs[i] = lbs[i - 1] + s[i];
	int l = 2, r = n, ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (chk(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}
