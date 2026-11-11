#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n = 0, m = 0, cnt = 0;
	cin >> n >> m;
	vector< long long > a(n);
	vector< long long > c(n - 1);
	for (long long i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (long long i = 1; i < n; ++i)
		c[i - 1] = (a[i] - a[i - 1]) * i;
	long long ccnt = 0, w = m;
	while (w >= 0)
	{
		w -= c[ccnt];
		++ccnt;
	}
	--ccnt;
	w += c[ccnt];
	--n;
	for (long long i = ccnt + 1; i < n - 1; ++i)
	{
		w = w + c[i - ccnt - 1] - c[i];
		while (w - c[i + 1] >= 0)
		{
			++ccnt;
			w -= c[i + 1];
			++i;
		}
		if (ccnt > cnt)
			cnt = ccnt;
	}
	if (ccnt > cnt)
		cnt = ccnt;
	cout << cnt + 1 << '\n';
	return 0;
}
