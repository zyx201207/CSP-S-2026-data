#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
int n, m;
vector<int> pre, cur;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		pre.emplace_back(x);
	}
	int ans = 0;
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		cur.clear();
		for (int i : pre) {
			bool d = ((i >> j) & 1);
			if (d) {
				++cnt;
				cur.emplace_back(i);
			}
		}
		if (cnt >= m) {
			pre = cur;
			ans += (1 << j);
		}
	}
	cout << ans << '\n';
	return 0;
}
