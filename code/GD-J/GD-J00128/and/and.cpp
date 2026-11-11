#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010], cnt[40], u[40][200010];
int ppp[40], ans;
bool ok[200010];

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int l = 0;
		while (a[i]) {
			u[++l][i] = a[i] % 2;
			a[i] /= 2;
		}
		for (int j = 1; j <= l; j++) {
			cnt[j] += u[j][i];
		}
	}
	ppp[1] = 1;
	for (int i = 2; i <= 30; i++) {
		ppp[i] = ppp[i-1] * 2;
	}
	for (int i = 30; i >= 1; i--) {
		if (cnt[i] >= m) {
			ans += ppp[i];
			for (int j = 1; j <= n; j++) {
				if (u[i][j] == 0) {
					if (ok[j] == 0) {
						for (int k = i; k >= 1; k--) {
							if (u[k][j]) cnt[k]--;
						}
						ok[j] = true;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
