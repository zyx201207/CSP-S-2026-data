#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int ans[MAXN], a[MAXN], c[MAXN], d[MAXN], n, m, tot, idx;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n < 501) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) c[j] = 0;
			tot = 0;
			for (int j = i; j <= n; j++) {
				idx = -1;
				for (int k = 1; k <= tot; k++) {
					if (c[k] == a[j]) {
						idx = k;
						break;
					}
				}
				if (idx == -1) c[++tot] = a[j];
				else {
					for (int k = 0; k <= n; k++) d[k] = 0;
					tot = 0;
					for (int k = 1; k < idx; k++) d[++tot] = c[k];
					d[++tot] = a[j];
					for (int k = 1; k <= tot; k++) c[k] = d[k];
				}
			}
			for (int j = 1; j <= tot; j++) ans[c[j]]++;
		}
	} else {
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] < a[i - 1]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			for (int i = 1; i < n; i++) {
				if (a[i] != a[i + 1]) ans[a[i]] = i;
			}
			ans[a[n]] = n;
		} else {
			for (int i = 1; i < n; i++) {
				if (a[i] != a[i + 1]) ans[a[i]] = i;
			}
			ans[a[n]] = n;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i];
		if (i < m) cout << ' ';
	}
	return 0;
}