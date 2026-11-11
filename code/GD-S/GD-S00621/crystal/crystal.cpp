#include <iostream>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, a[N], sum[N];

bool check(int x) {
	for(int i = x; i <= n; i++) {
		if(a[i] * x - (sum[i] - sum[i - x]) <= m) return 1; 
	}
	return 0;
}

signed main() {//AC! 100pts 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = n, res = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			l = mid + 1;
			res = mid;
		}
		else r = mid - 1;
	}
	cout << res << endl;
	return 0;
}
