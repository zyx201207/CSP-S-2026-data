#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], pre[N];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, greater<int>());
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int aans = 0;
	for(int i = 1; i <= n; i++) {
		int L = i + 1, R = n, ans;
		while(L <= R) {
			int mid = L + R >> 1;
			if(a[i] * (mid - i) - (pre[mid] - pre[i]) <= m) ans = mid - i + 1, L = mid + 1;
			else R = mid - 1;
		}
		aans = max(aans, ans);
	}
	cout << aans << "\n";
	return 0;
}