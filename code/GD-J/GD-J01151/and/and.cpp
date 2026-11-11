#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;

int n, m;
vector<int> a, b;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m; 
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int ans = 0;
	for (int i = 30; i >= 0; --i) {
		int cnt = 0; b.clear();
		for (auto x : a) {
			if ((x >> i) & 1) {
				b.push_back(x);
				cnt += 1;
			}
		}
		if (cnt >= m) {
			a.swap(b);
			ans |= (1 << i);
		}
	}
	cout << ans;
    return 0;
}
