#include <bits/stdc++.h>
using namespace std;

const int N = 2000000;

int n; long long d, x[N + 10];
int l[N + 10], r[N + 10];
int val1[N + 10], val2[N + 10], tot[N + 10];

void work() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	
	fill(l, l + n + 2, n + 1), fill(r, r + n + 2, 0);
	for (int i = 1, j = 1; i <= n; ++i) {
		while (j < i && x[i] - x[j] > d) ++j;
		l[i] = j;
	}
	for (int i = n, j = n; i >= 1; --i) {
		while (j > i && x[j] - x[i] > d) --j;
		r[i] = j;
	}
	fill(val1 + 1, val1 + n + 1, 0), fill(val2 + 1, val2 + n + 1, 0);
	
	fill(tot + 1, tot + n + 1, 0);
	for (int i = n; i >= 1; --i) {
		if (l[i] == i) continue;
		if (i - 1 > l[i]) ++val1[l[i]];
		if (i - 1 > l[i] && r[l[i] + 1] == i) val1[l[i]] += tot[i];
		++tot[l[i]]; if (l[i + 1] > l[i]) tot[l[i]] += tot[i];
	}
//	for (int i = 1; i <= n; ++i) cout << val1[i] << ' '; cout << '\n';
	fill(tot + 1, tot + n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (r[i] == i) continue;
		if (i + 1 < r[i]) ++val2[r[i]];
		if (i + 1 < r[i] && l[r[i] - 1] == i) val2[r[i]] += tot[i];
		++tot[r[i]]; if (r[i - 1] < r[i]) tot[r[i]] += tot[i];
	}
//	for (int i = 1; i <= n; ++i) cout << val2[i] << ' '; cout << '\n';
	
	long long ans = 0;
	for (int i = 1; i < n; ++i) ans += (long long)val1[i] * val2[i + 1];
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	int _c, T; cin >> _c >> T; while (T--) work();
	return 0;
}

// chennie bless me

/*
0 1
4 2
1 2 3 4

1

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1

0 1
5 5
1 4 5 6 9

0

0 1
6 5
1 5 6 10 11 15

3
*/ 
