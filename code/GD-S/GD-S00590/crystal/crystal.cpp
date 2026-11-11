#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n, m, a[N], pref[N];

bool check(int len)
{
	long long mi = 2e18;
	for(int i = len; i <= n; i++)
	{
		int l = i - len + 1;
		long long tmp = pref[i] - pref[l - 1];
		mi = min(mi, a[i] * len - tmp);
	}
	return mi <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] + a[i];
	}
	
	long long l = 1, r = n, ans = -1;
	while(l <= r)
	{
		long long mid = l + (r - l >> 1);
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
