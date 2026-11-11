#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;
ll read(ll x = 0) {
	bool f = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = 1;
		c = getchar();
	}
	while (isdigit(c))
		x = x * 10ll + c - '0',
		c = getchar();
	return f ? -x : x;
}
ll x[N]; int p[N], s[N], f[N], g[N];
void work() {
	int n; ll d;
	scanf("%d", &n), d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	for (int i = 1, j = 1; i <= n; i++) {while (x[i] - x[j] > d) ++j; p[i] = j;}
	for (int i = n, j = n; i >= 1; i--) {while (x[j] - x[i] > d) --j; s[i] = j;}
	for (int i = 1; i < n; i++) f[i] = p[i] == p[i + 1] ? 1 : f[p[i]] + p[i + 1] - p[i];
	for (int i = n; i > 1; i--) g[i] = s[i] == s[i - 1] ? 1 : g[s[i]] + s[i] - s[i - 1];
	ll ans = 0;
	for (int i = 2; i < n - 1; i++)
		if (p[i + 1] < i && s[i] > i + 1 && p[i + 1] < p[i + 2] && s[i] > s[i - 1])
			ans += 1ll * ((p[i] == p[i + 1] ? f[p[i + 1]] : 1) + p[i + 2] - p[i + 1] - 1) *
						 ((s[i] == s[i + 1] ? g[s[i]] : 1) + s[i] - s[i - 1] - 1);
	printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int id, T;
	scanf("%d%d", &id, &T);
	while (T--) work();
	return 0;
}
