#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5005], vis[5005][5005], cha;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool okok = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2) {
			cha = a[i] - a[i - 1];
		} else if (i > 2) {
			if (a[i] - a[i - 1] != cha) {
				okok = false;
			}
		}
	}
	if (okok) {
		long long o = m / cha;
		for (int i = 1; i <= n; i++) {
			if (o - i < 0) {
				cout << i;
				break;
			} else {
				o -= i;
			}
		}
		return 0;
	}
	sort (a + 1, a + n + 1);
	int ii = 1;
	for (int i = 2; i <= n; i++) {
		vis[ii][i] = a[i] - a[ii];
		ii++;
	}
	int o = 3;
	for (int i = 1; i <= n; i++) {
		for (int j = o; j <= n; j++, i++) {
			vis[i][j] = vis[i][i + 1] + vis[i + 1][j];
		}
		i = 0;
		o++;
		if (o == n + 1) {
			break;
		}
	}
	long long maxn = 0, ans = 0;
	for (int j = 2; j <= n; j++) {
		long long sum = 0;
		for (int i = 1; i < n; i++) {
			sum += vis[i][j];
		}
		if (sum <= m) {
			if (sum >= maxn) {
				ans = j;
				maxn = sum;
			}
		}
	}
	cout << ans;
	return 0;
}
