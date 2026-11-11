#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define pre(i, n, a) for (int i = (n); i >= (a); i--)
#define pb push_back
#define eb emplace_back
#define mp std::make_pair
#define SZ(x) (int)((x).size())
#define all1(x) (x).begin(), (x).end()
#define all(x) (x).begin() + 1, (x).end()
typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
std::mt19937 mrand(std::random_device{}());
int rnd(int x) { return mrand() % x; }
// head

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	int n;
	ll m;
	scanf("%d%lld", &n, &m);

	// a[i] < 0 || a[i] = 0 || a[i] > 0
	std::vector<ll> a(n + 1);
	rep(i, 1, n) scanf("%lld", &a[i]);

	std::sort(all(a));

	std::vector<ll> s(n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];

	int ans = 0;
	rep(i, 1, n) {
		int L = 0, R = i + 1;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			ll sum = s[i] - s[M - 1];
			ll tot = ll(i - M + 1) * a[i];
			if (tot - sum <= m) R = M;
			else L = M;
		}
		ans = std::max(ans, i - L);
	}

	printf("%d\n", ans);

	return 0;
}
/*

*/