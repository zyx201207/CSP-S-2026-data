#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5, M = 3e5 + 5;

int n, a[N], m, ans, vis[N];
vector<int> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int f = 0, c = 0;
			for (int s : v) {
				if (f == 1) {
					c++;
				}
				if (s == a[j]) {
					f = 1;
				}
			}
			if (f) {
				for (int k = 1; k <= c; k++) {
					v.pop_back();
				}
			} else {
				v.push_back(a[j]);
			}
		}
		for (int s : v) {
			vis[s]++;
		}
		v.clear();
	}
	for (int i = 1; i <= m; i++) {
		cout << vis[i] << ' ';
	}
	return 0;
}
