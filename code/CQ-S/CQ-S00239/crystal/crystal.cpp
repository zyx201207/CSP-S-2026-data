#include <bits/stdc++.h>
using namespace std;

bool ST;

const int N = 5e5 + 5;
long long n, m, a[N], sum[N];

bool ED;

int main () {

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	
	sort (a + 1, a + n + 1);
	long long ans = 1, pos = 1, sum = a[1];
	for (long long i = 2; i <= n; ++i) {
		sum += a[i];
		while (pos < i && a[i] * (i - pos + 1) - sum > m) sum -= a[pos++];
		ans = max (ans, i - pos + 1);
	}
	cout << ans;
	
	return 0;
}
