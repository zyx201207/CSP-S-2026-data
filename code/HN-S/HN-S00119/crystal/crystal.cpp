#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

ll n, m, ans;
ll a[N], sum[N];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (ll i = 1, j = 1; i <= n; i++) {
		for (; j + 1 <= n && a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m; j++) ;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}

