#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll n, D, x[N], ind[N], d[N], f[N], ans;
queue<int> q;
vector<int> F[N], G[N];
void clear() {
	n = D = 0;
	for (int i = 1; i <= n; i++) {
		x[i] = ind[i] = d[i] = f[i] = 0;
		F[i].clear(), G[i].clear();
	}
	ans = 0; while (q.size()) q.pop();
	
}
void add(int x, int y) {
	G[x].push_back(y);
}
void link(int x, int y) {
//	cout << x << " " << y << '\n';
	F[x].push_back(y);
	ind[y]++;
}
void work(int s) {
//	cout << s << '\n';
	for (int i = 1; i <= n; i++) d[i] = 0, F[i].clear(), f[i] = ind[i] = 0;
	d[s] = 1; q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto y : G[x]) {
			if (!d[y]) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (x[j] - x[i] <= D && d[j] == d[i] + 1) {
				link(i, j);
			}
		}
	}
	f[s] = 1; q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto y : F[x]) {
			f[y] = min(3ll, f[y] + f[x]);
			if (!(--ind[y])) q.push(y);
		}
	}
	for (int i = s; i <= n; i++) {
		if (f[i] == 2) ans += 1;
//		cout << i << " " << f[i] << '\n';
	}
	return;
}
void work() {
	cin >> n >> D;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (x[j] - x[i] <= D) add(i, j);
		}
	}
	for (int i = 1; i <= n; i++) work(i);
	cout << ans << '\n';
	return;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T; cin >> c >> T;
	while (T--) work(), clear();
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/