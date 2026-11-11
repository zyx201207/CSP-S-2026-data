#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 7;
const int MAXM = 3e1 + 7;
int n, m, ans;
int a[MAXN], pw[MAXM];
int b[MAXN][MAXM];
bool val[MAXN];
void f(int x) {
	int pos = 0;
	while (a[x]) {
		b[x][pos] = a[x] % 2;
		a[x] /= 2;
		pos++;
	}
	return;
}
void init() {
	pw[0] = 1;
	for (int i = 1; i < MAXM; i++) pw[i] = pw[i - 1] * 2;
	return;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		val[i] = 1;
	}
	for (int i = 1; i <= n; i++) f(i);
	for (int i = MAXM - 1; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!val[j]) continue;
			if (b[j][i]) cnt++;
		} 
		if (cnt >= m) {
			ans += pw[i];
			for (int j = 1; j <= n; j++) {
				if (!val[j]) continue;
				if (!b[j][i]) val[j] = 0;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
