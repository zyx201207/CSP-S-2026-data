#include <bits/stdc++.h>

using ll = long long;
#define f first
#define s second
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 2e5 + 10;
int n, cnt;
ll ans, a[N], sum[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char ch;
		std::cin >> x >> ch;
		if (cnt && ch == c[cnt]) a[cnt] += x;
		else a[++cnt] = x, c[cnt] = ch;
	}
	n = cnt;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		if (sum[i - 1] + 1 > (sum[n] >> 1)) break;
		ll x = sum[n] - sum[i - 1], y = sum[n] - std::min(sum[i], (sum[n] >> 1)) + 1;
		int p1 = std::lower_bound(sum + 1, sum + n + 1, x) - sum, p2 = std::lower_bound(sum + 1, sum + n + 1, y) - sum;
		if (c[p1] != c[i]) ans += x - std::max(y - 1, sum[p1 - 1]);
		if (p1 != p2 && c[p2] != c[i]) ans += std::min(x, sum[p2]) - y + 1;
		for (int j = p2 + 1; j < p1; j++) if (c[j] != c[i]) ans += a[j];
	}
	std::cout << ans << '\n';
	return 0;
}
