#include <bits/stdc++.h>
#define itn long long 
using namespace std;
constexpr int N = 5e5 + 5;
itn n, m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	itn sum = 0, cur = 0, ans = 0, l = 1;
	for (int i = 2; i <= n; ++i) {
		if (sum + (cur + 1) * (a[i] - a[i - 1]) <= m) {
			++cur;
			sum += cur * (a[i] - a[i - 1]);
		} else {
			ans = max(ans, cur);
			++cur;
			sum += cur * (a[i] - a[i - 1]);
			while (sum > m) {
				sum -= a[i] - a[l];
				--cur, ++l;
			}
		}
	}
	ans = max(ans, cur);
	cout << ans + 1;
	return 0;
}

// start on 14:30; complete on 14:48; check on 18:23
