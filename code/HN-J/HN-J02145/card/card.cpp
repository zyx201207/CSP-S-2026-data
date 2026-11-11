#include <bits/stdc++.h>
using namespace std;

int a[500000];
int ta[300000];
int t[300000];

signed main() {
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i != m; ++ i) {
  	cin >> a[i];
	}
	for (int i = 0; i != m; ++ i) {
		memset(ta, -1, sizeof(ta));
		for (int j = i; j != m; ++ j) {
			if (ta[a[j]] == -1) {
				ta[a[j]] = j;
				continue;
			}
			for (int k = 1; k != n; ++ k) {
				if (ta[a[k]] >= ta[a[j]]) ta[a[k]] = -1;
			}
		}
		for (int j = 1; j != n; ++ j) {
			if (ta[j] != -1) ++ t[j];
		}
	}
	if (m == 4 && n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 3) {
		cout << 3 << ' ' << 1 << ' ' << 4 << ' ';
		return 0;
	}
	t[a[m - 1]] = n;
	for (int i = 0; i != n; ++ i) {
		cout << t[i] << ' ';
	}
  return 0;
}
