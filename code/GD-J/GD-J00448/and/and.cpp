#include <bits/stdc++.h>
using namespace std;

const int N = 201000;
int n, m, a[N];
multiset<int> s;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}
	int ans = 0;
	for (int j = 30; j >= 0; j--) {
		int cnt1 = 0;
		for (auto x : s)
			if (x & (1 << j)) cnt1 += 1;
		if (cnt1 >= m) {
			ans += 1 << j;
			vector<int> rem;
			for (auto x : s) if (!(x & (1 << j))) {
				rem.push_back(x);
			}
			for (auto x : rem) s.erase(x);
		}
	}
	printf("%d\n", ans);
	return 0;
}