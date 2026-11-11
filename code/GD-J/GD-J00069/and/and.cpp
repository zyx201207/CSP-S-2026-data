#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[200010];
bool b[200010], ob[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	ll ans = 0;
	bool first = false;
	for (int k = 30; k >= 0; k--) {
		for (int i = 1; i <= n; i++) b[i] = false;
		vector<int> v;
		for (int i = 1; i <= n; i++) if ((a[i] >> k) & 1) {
			v.push_back(i);
		}
		if ((int)v.size() < m) continue;
		if (!first) {
			ans |= 1 << k;
			for (auto x : v) b[x] = true;
			first = true;
			for (int i = 1; i <= n; i++) ob[i] = b[i];
		} else {
			int cnt = 0;
			for (auto x : v) if (ob[x]) {
				b[x] = true; cnt++;
			}
			if (cnt >= m) {
				ans |= 1 << k;
				for (int i = 1; i <= n; i++) ob[i] = b[i];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

