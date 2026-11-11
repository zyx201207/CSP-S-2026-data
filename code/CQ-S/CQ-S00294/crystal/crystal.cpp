#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005];
__int128 sum[500005], c[500005], prec[500005];
bool check(int len, int r) {
	int l = r - len + 1;
	__int128 need = sum[r] - sum[l] - (r - len) * (prec[r] - prec[l]);
//	if (r == 5) {
//		cout << 5 << ' ' << len << ' ' << need << '\n';
//	}
//	cout << l << ' ' << r << ' ' << need << '\n';
//	cout << sum[r] << ' ' << sum[l] << '\n';
	return (need <= m);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
		prec[i] = prec[i - 1] + c[i];
		sum[i] = sum[i - 1] + c[i] * (i - 1); 
//		cout << sum[i] << ' ' << c[i] << '\n';
		
	} 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		int cnt = 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				cnt = mid;
				l = mid + 1; 
			}
			else {
				r = mid - 1;
			}
		}	
//		cout << i << ' ' << cnt << '\n';
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}

