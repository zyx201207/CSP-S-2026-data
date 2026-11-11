#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[500005], b[300005], cnt[300005], q[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		k = 1;
		for (int j = i; j <= n; j++) {
			if (b[a[j]] == 0) {
				q[k] = a[j];
				b[a[j]] = k;
				k++;
			} else {
				for (int m = b[a[j]] + 1; m <= k; m++) {
					b[q[m]] = 0;
					q[m] = 0;
				}
				k = b[a[j]] + 1;
			}
		}
		for (int j = 1; j < k; j++) {
			cnt[q[j]]++;
			b[q[j]] = 0;
			q[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}
