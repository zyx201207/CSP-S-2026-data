#include<bits/stdc++.h>
#define int long long
using namespace std;

const int max_n = 5e5 + 5;

int n, m;
int a[max_n], b[max_n];

inline bool check(int x) {
	
	for (int i = 1; i + x - 1 <= n; i++) {
		int j = i + x - 1;
		
		int ans = a[j] * x - (b[j] - b[i - 1]);
		
		if (ans <= m) return true;
	}
	
	return false;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	
	int l = 0, r = n, ans = 0;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	
	cout << ans;
	
	return 0;
}