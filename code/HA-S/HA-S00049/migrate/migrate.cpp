#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 10;
const int INF = 1 << 30;

int c, n, f[N][3];
ll d, a[N];

void upd(int i, int v) {
	if (v <= f[i][0]) {
		f[i][2] = f[i][1];
		f[i][1] = f[i][0];
		f[i][0] = v;
	} else if (v <= f[i][1]) {
		f[i][2] = f[i][1];
		f[i][1] = v;
	} else if (v <= f[i][2]) {
		f[i][2] = v;
	}
}

void subtask() {
	if (n == 1) {
		printf("0\n");
		return;
	} 
	d /= a[2] - a[1];
	if (d <= 1) {
		printf("0\n");
		return;
	}
	printf("%lld\n", max(0LL, n + 1 - 2 * d));
} 

void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	bool ok = true;
	for (int i = 2; i <= n; i++)
		if (a[i] - a[i - 1] != a[2] - a[1]) ok = false;
	if (ok) {
		subtask();
		return;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			for (int k = 0; k < 3; k++)
				f[j][k] = INF;
		f[i][0] = 0;
		for (int j = i; j <= n; j++) {
			if (i < j && f[j][0] == f[j][1] && f[j][1] != f[j][2])
				ans++;
			for (int k = 0; k < 3; k++)
				for (int l = j + 1; l <= n; l++) {
					if (a[l] - a[j] > d) break;
					upd(l, f[j][k] + 1);
				}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int test;
	scanf("%d%d", &c, &test);
	for (; test--; ) solve();
	return 0;
}

