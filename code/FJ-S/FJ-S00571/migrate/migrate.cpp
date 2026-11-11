#include<bits/stdc++.h>
#define int long long
using namespace std;

const int max_n = 1e6 + 5;

int c, t, n, d;
int x[max_n];

int ans = 0x3f3f3f3f, cnt = 0;

inline bool check(int l, int r) {
	int lt = 1, rt = 2e18, ans = 0;
	while (lt <= rt) {
		int mid = (lt + rt) >> 1;
		if (upper_bound(x + l, x + r + 1, x[l] + d * mid) - x - 1 >= lower_bound(x + l, x + r + 1, x[r] - d * mid) - x) {
			rt = mid - 1;
			ans = mid;
		}
		else {
			lt = mid + 1;
		}
	}
	return (upper_bound(x + l, x + r + 1, x[l] + d * ans) - x - 1) != (lower_bound(x + l, x + r + 1, x[r] - d * (ans - 1)) - x)
	    && (lower_bound(x + l, x + r + 1, x[r] - d * ans) - x) != (upper_bound(x + l, x + r + 1, x[l] + d * (ans - 1)) - x - 1);
	//......
}

inline void f(int l, int r, int z) {
	if (l == r) {
		if (z  == ans) cnt++;
		if (z < ans) ans = z, cnt = 1;
		
		return ;
	}
	
	for (int i = l + 1; i <= r; i++) {
		if (x[l] + d < x[i]) break;
		f(i, r, z + 1);
	}
}

inline bool check1(int l, int r) {
	ans = 0x3f3f3f3f, cnt = 0;
	f(l, r, 0);
	return cnt == 2;
}

vector<pair<int, int>> y;

inline void solve() {
	y.clear();
	cin >> n >> d;
	int last = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (x[i] - x[i - 1] > d) y.push_back({last, i - 1}), last = i;
	}
	
	y.push_back({last, n});
	
	if (1 <= c && c <= 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (check1(i, j)) ans++;
			}
		}
			
		cout << ans << "\n";
		return ;
	}
	
	if (3 <= c && c <= 10) {
		int ans = 0;
		for (auto k : y) {
			for (int i = k.first; i <= k.second; i++) {
				for (int j = i + 2; j <= k.second; j++) {
					if (check(i, j)) {
						//cout << i << " " << j << "\n";
						ans++;
					}
				}
			}
		}
		cout << ans << "\n";
		return ;
	}
	
	cout << 0;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t--) solve();
	
	return 0;
}