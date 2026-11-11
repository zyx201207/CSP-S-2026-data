#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m, ans[N], ans1, t;
int a[N], b[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	b[1] = a[1];
	for (int i = 2; i <= n; i++)
		b[i] = a[i] - a[i - 1];
	ans1 = 1;
	for (int i = 2; i <= n; i++) {
		ans[i] = 1;
		int m1 = m;
		for (int j = i; j <= n; j++) {
			if (m1 - b[j] < 0) break;
			m1 -= b[j];
			ans[i]++;
		}
		ans1 = max(ans1, ans[i]);
	}
	cout << ans1 << endl;
	return 0;
}

