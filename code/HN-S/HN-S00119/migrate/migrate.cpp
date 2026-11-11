#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 5;

ll c, T, n, d, ans; 
ll x[N], nxt[N];

void Clear() {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		x[i] = nxt[i] = 0;
	}
	return ;
}

void Solve() {
	Clear();
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1, j = 1; i <= n ; i++) {
		for (; j + 1 <= n && x[j + 1] <= x[i] + d; j++) ;
		nxt[i] = j;
	}
	for (int i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j++) {
			int cnt = 0;
			for (int k = nxt[i]; k < j; k = nxt[k]) {
				int y = min(j, nxt[k]);
				if (k == y) {
					cnt = 0;
					break;
				}
				if (k > 1 && k - 1 >= i && x[k - 1] + d >= x[y]) {
					cnt++;
				}
				if (k > 2 && k - 2 >= i && x[k - 2] + d >= x[y]) {
					cnt++;
				}
			}
			ans += cnt == 1;
		}
	}
	cout << ans << '\n';
	return ;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	for (cin >> c >> T; T--; Solve()) ;
	return 0;
}



