#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;

int n; ll m, a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1); ll sum = a[1]; int ans = 0;
	for (int i = 1, j = 1; i <= n; ) {
		for (; j < i && (ll)a[i] * (i - j + 1) - sum > m; sum -= a[j++]);
		ans = max(ans, i - j + 1), sum += a[++i];
	}
	printf("%d", ans);
}
