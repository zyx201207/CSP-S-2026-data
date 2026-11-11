#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, vis[N], s, h, fl;
char c[N];
ll pre[N], a[N], g, g2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (c[i - 1] == c[i]) {
			a[i] += a[i - 1];
			a[i - 1] = 0;
			vis[i] = 1;
			s++;
		}
		g += a[i];
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		g2 += a[i];
		if (g2 >= g / 2 && !fl) {
			h = i;
			while (vis[h]) {
				h--;
			}
			fl = 1;
		}
	}
	ll l = 0, sum = 0;
	int b = 0;
	for (int i = 0, j = n + 1; i < j;) {
		if (l > 0) {
			j--;
			l -= a[j];
			while (vis[j]) {
				j--;
			}
		} else if (l < 0) {
			i++;
			l += a[i];
			while (vis[i]) {
				i++;
			}
		} else {
			i++, j--;
			l += a[i] - a[j];
			while (vis[i]) {
				i++;
			}
			while (vis[j]) {
				j--;
			}
		}
		if (c[i] == c[j]) {
			if (l > 0) {
				sum += min(1ll * a[j], l);
			} else if (l < 0) {
				sum += min(1ll * a[i], l * -1);
			} else {
				if (i + 1 == j) {
					sum += max(a[i], a[j]);
				}
				sum += min(a[i], a[j]);
			}
		}
	}
	if (n == s + 1) {
		cout << 0;
		return 0;
	}
	cout << max(pre[h], pre[n] - pre[h]) - sum;
	return 0;
}
/*
4
3 c
2 b
2 c
1 f
*/
/*
3
2 a
2 b
1 c
*/
/*
6
1000 a
1000 a
1000 a
1000 b
1000 b
1000 b
*/
/*
4
3 c
1 b
1 c
1 f
*/
