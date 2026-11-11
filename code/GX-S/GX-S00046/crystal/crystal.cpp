#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, s[500001], a[500001], f[500001];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1ll; i <= n; i++) {
		cin >> a[i];
		for (long long j = 1ll; j < i; j++) s[i] += max(0ll, a[i] - a[j]);
		if (s[i - 1] <= m && s[i] > m) {
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}