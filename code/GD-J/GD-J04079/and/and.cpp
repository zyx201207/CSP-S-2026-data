#include <bits/stdc++.h>
using namespace std;
int n, m;
struct t {
	int val, cnt;
} a[200005];
bool cmp(t a, t b) {
	return a.cnt == b.cnt ? a.val > b.val : a.cnt > b.cnt;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		int x = a[i].val;
		while (x) {
			if (x % 2)
				a[i].cnt++;
			x /= 2;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	int sum = INT_MAX;
	for (int i = 1; i <= m; i++) {
		sum = sum & a[i].val;
	}
	cout << sum;
	return 0;
}