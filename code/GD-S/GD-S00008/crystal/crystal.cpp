#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 5;
typedef long long LL;
int n;
LL m;
LL a[N], s[N];

int bound(int x) {
	int l = 0, r = x + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (a[x] * (x - mid) - s[x - 1] + s[mid - 1] <= m) r = mid;
		else l = mid;
	}
	return r;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, i - bound(i) + 1);
	}
	cout << ans << endl;
	return 0;
}
