#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i <= b; i ++ )
#define per(i, a, b) for (int i = a; i >= b; i -- )
#define pb push_back
#define pii pair<int, int>
#define L first
#define R second
void _max(int &a, int b) {a = max(a, b); }
void _min(int &a, int b) {a = min(a, b); }

// migrate

const int N = 2e6 + 5;

int n, d, x[N], l[N], r[N], L[N], R[N];
vector <pii> v;

void solve() {
	cin >> n >> d;
	v.clear();
	rep(i, 1, n) cin >> x[i];
	L[1] = 1;
	for (int i = 2; i <= n; i ++ ) {
		if (x[i] - x[i - 1] <= d) 
			L[i] = L[i - 1];
		else L[i] = i;
	}
	R[n] = n;
	for (int i = n - 1; i >= 1; i -- ) {
		if (x[i + 1] - x[i] <= d) 
			R[i] = R[i + 1];
		else R[i] = i;
	}
	l[1] = 1;
	for (int i = 2, j; i <= n; i ++ ) {
		j = l[i - 1];
		while (x[i] - x[j] > d) j ++ ;
		l[i] = j;
	}
	r[n] = n;
	for (int i = n - 1, j; i >= 1; i -- ) {
		j = r[i + 1];
		while (x[j] - x[i] > d) j -- ;
		r[i] = j;
	}
	for (int i = n, lp = n, rp = n, p = n; i >= 1; i -- ) {
		while (p > i && l[p] > r[i] - 1) p -- ;
		if (l[p] == r[i] - 1 && x[p] - x[i] > d) 
			v.pb({i, p});
	}
	sort(v.begin(), v.end());
	int m = v.size(), res = 0;
	rep(i, 0, m - 1) {
		int x = v[i].L, y = v[i].R;
		res += max(x - max(L[x], ((i - 1 >= 0) ? (v[i - 1].L) : (0)) + 1) + 1, 0ll) * 
			   max(min(R[y], ((i + 1 < m) ? v[i + 1].R : (n + 1)) - 1) - y + 1, 0ll);
	}
	cout << res << '\n';
	return ;
}

/*
0 1
6 12
-10 -6 -2 2 6 10
*/

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T = 1;
	cin >> c >> T;
	while (T -- ) solve();
	return 0;
}

