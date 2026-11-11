#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], head = 0, tail = 0, now = 0, ans = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		now = now + (a[i] - a[i - 1]) * (tail - head);
		tail++;
		while(tail - head && now > m) {
			now -= a[tail] - a[head++];
		}
		ans = max(ans, tail - head);
	}
	cout << ans;
	return 0;
}

