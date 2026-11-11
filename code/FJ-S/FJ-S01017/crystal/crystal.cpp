#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N = 1000010;
const int inf = 1e18;
int n, m;
int a[N], pre[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	For(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	For(i, 1, n) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	For(i, 1, n) {
		int l = 1, r = i, res = inf;
		while (l <= r) {
			int mid = (l + r) / 2;
			if(a[i] * (i - mid + 1) - pre[i] + pre[mid - 1] <= m) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
} 
