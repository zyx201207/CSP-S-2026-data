#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Max(a, b) a = max(a, b)
#define pp pair<int, int>
#define ft first
#define sd second
const int N = 5e5 + 5;
int n, m, a[N], s[N], d[N], ans;
bool ck(int i, int j) {
	int z = a[j] * (j - i);
	z -= s[j - 1] - s[i - 1];
	return z <= m;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) 
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (ck(mid, i)) r = mid - 1, d[i] = mid;
			else l = mid + 1;
		}
		Max(ans, i - d[i] + 1);
	}
	cout << ans;
	return 0; 
}
