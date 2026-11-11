#include <bits/stdc++.h>
using namespace std;
#define int long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int n, m, a[500010], s[500010];
bool check(int x, int L) { // x~L -> s[x + 1] - s[L + 1] - (L - x) * a[L + 1]
	if(s[x + 1] - s[L + 1] - (L - x) * a[L + 1] <= m) return true;
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	int lst = 0;
	for(int i = 1; i <= n; i++) {
		int x = a[i];
		a[i] = x - lst, lst = x;
	}
	for(int i = n; i >= 1; i--) {
		a[i] = a[i + 1] + a[i];
		s[i] = a[i] + s[i + 1];
	}
	
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		int l = 1, r = i - 1, mid; // Ñ¡Ôñ±àºÅ [mid, i - 1] Ë®¾§ 
		while(l <= r) {
			mid = l + r >> 1;
			if(check(mid, i)) {
				r = mid - 1;
				ans = max(ans, i - mid + 1);
			}else l = mid + 1;
		}
	}
	cout << ans; 
	return 0;
} 
