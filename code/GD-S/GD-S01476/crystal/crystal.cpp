#include <bits/stdc++.h>

using namespace std;

long long n, m, ans = 0;
long long a[500001], s[500001], ss[500001];
bool b = true, c = true; //特殊性质A,B
long long lcc; //特殊性质B

int cmp(const int x, const int y) {
	return x < y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] != i) {
			b = false;
		}
		if (i == 0) {
			continue ;
		}
		else if (i == 1) {
			lcc = a[1] - a[0];
		}
		else if (a[i] - a[i - 1] != lcc) {
			lcc = false;
		} 
	}
	if (b) {
		for (int i = 1; i <= n; i ++) {
			if (m <= i * (i + 1) / 2) {
				cout << i << endl;
				return 0;
			}
		}
	}
	if (c) {
		for (int i = 1; i <= n; i ++) {
			if (m <= lcc * i * (i + 1) / 2) {
				cout << i << endl;
				return 0;
			}
		}
	}
	sort(a, a + n, cmp);
	for (int i = 1; i < n; i ++) {
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * i;
		ss[i] = ss[i - 1] + a[i] - a[i - 1];
	}
	for (int i = 1; i < n; i ++) {
		long long k = upper_bound(s + i, s + n - 1, m) - (s + i);
		ans = max(ans, k + 1);
		for (int j = i + 1; j < n; j ++) {
			s[j] -= ss[j];
			ss[j] -= a[i] - a[i - 1];
		}
	}
	cout << ans << endl;
	return 0;
}
