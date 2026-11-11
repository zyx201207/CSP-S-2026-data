#include <bits/stdc++.h>
using namespace std;

int n, mx;
long long m;
long long a[500005], s[500005];

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		s[i] = s[i - 1] + a[i];
		int l = 0, r = i - 1, ans = i - 1;
		long long val = s[i] - a[i] * i + m;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (s[mid] - a[i] * mid <= val)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		mx = max(mx, i - ans);
	}
	cout << mx;
	return 0;
}
