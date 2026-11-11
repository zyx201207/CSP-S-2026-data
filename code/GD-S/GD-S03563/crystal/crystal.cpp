#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

int n, m, a[500010], d[500010];
bool check(int x)
{
	for(int i = x; i <= n; i++)
	{
		int sum = d[i] - d[i - x], p = a[i] * x;
		if(p - sum <= m) return 1;
	}
	return 0;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) d[i] = d[i - 1] + a[i];
	int l = 0, r = n, ans = -1;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
