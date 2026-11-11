#include<bits/stdc++.h>
using namespace std;

signed main()
{
	ifstream cin("crystal.in");
	ofstream cout("crystal.out");
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long>a(n + 1);
	vector<long long>pre(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; ++i)
	{
		pre[i] = a[i];
		pre[i] += pre[i - 1];
	}
	long long l = 1, r = 1;
	long long ans = 0;
	for (l = 1; l <= n; ++l)
	{
		while (r <= n && a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) <= m)
		{
			++r;
		}
		ans = max(ans, r - l);
	}
	cout << ans;
}