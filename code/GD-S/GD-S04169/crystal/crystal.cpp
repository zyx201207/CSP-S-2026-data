#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, ans = 1; ll m;
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	ll sum = 0;
	for (int i = 2, j = 1; i <= n; i++) {
		sum += 1ll * (a[i] - a[i - 1]) * (i - j);
		while (sum > m) sum -= a[i] - a[j], ++j;
		ans = max(ans, i - j + 1);
	}
	return printf("%d", ans), 0;
}
