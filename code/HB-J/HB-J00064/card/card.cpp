#include <bits/stdc++.h>
using namespace std;

int n, m, a[5005], b[3005], c[5005], t, cnt[3005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		t = 0;
		for (int j = i; j <= n; j++) {
			if (b[j] == 0) {
				c[++t] = j;
				b[j] = t;
			} else {
				for (int k = b[j] + 1; k <= t; k++) b[c[k]] = 0;
				t = b[j];
			}
		}
		for (int j = 1; j <= t; j++) cnt[c[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << c[i];
 	return 0;
}
