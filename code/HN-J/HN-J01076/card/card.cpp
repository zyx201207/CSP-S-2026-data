#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int n, m, a[N], cnt[N], pos[N];
int lt[N], rt[N];

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		for (int i = 1; i <= n; ++i) cnt[a[i]] = pos[a[i]] = lt[a[i]] = 0;
		for (int j = i; j <= n; ++j) {
			if (cnt[a[j]]) {
				for (int k = pos[a[j]]; k <= j; ++k) lt[k] = 1;
				cnt[a[j]] = 1, pos[a[j]] = j;
			}
			else {
				cnt[a[j]] = 1;
				pos[a[j]] = j;
			}
		}
		for (int j = i; j <= n; ++j) {
			if (!lt[j]) rt[a[j]]++;
		}
	}
	for (int i = 1; i <= m; ++i) cout << rt[i] << ' ';
	return 0;
} 
