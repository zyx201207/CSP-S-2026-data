#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], prefix[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 1, j = 1; i <= j; ) {
		int v = prefix[j] - prefix[i - 1], l = j - i + 1;
		if (a[j] * l - v <= m) {
			ans = max(ans, l);
			if (j < n) j++;
			else i++;
		} else {
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}
