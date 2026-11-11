#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 5e5 + 5;

int n; ll m, a[N], d[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); 
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		int l = 1, r = i, pos = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if ((i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) r = mid - 1, pos = mid;
			else l = mid + 1;			
		}
		ans = max(ans, i - pos + 1);
	}
//	for (int i = 1; i <= n; ++i) cout << s[i] << ' '; cout << '\n';
//	for (int i = 1; i <= n; ++i) cout << ss[i] << ' '; cout << '\n';
	cout << ans;
	/*
	d -> ai - ai-1
	a_n - a_n-1 + a_n-1 - a_n-2 +... + a_i - a_i-1
	a_n - a_i
	*/
} 
