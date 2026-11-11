#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10, M = 3e5 + 10;
int a[N], is[M], cnt[M], lst[M], has[M], r[N], l[N], p[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) lst[j] = -1;
		for (int j = 1; j <= m; j++) has[j] = 0;
		for (int i = 1; i <= n; i++) p[i] = -1;
		for (int j = i; j <= n; j++) {
			if (lst[a[j]] != -1) { // ½«lst[a[j]]ÖÁj-1É¾³ý 
				for (int k = lst[a[j]]; k < j; k++) {
					if (p[k] != -1) k = p[k];
					if (k >= j) break;
					lst[a[k]] = -1;
					has[a[k]] = false;
					p[k] = j;
				}
			}
			lst[a[j]] = j;
			has[a[j]] = true;
		}
		for (int j = 1; j <= m; j++) cnt[j] += has[j]; 
	}
	for (int j = 1; j <= m; j++) {
		cout << cnt[j];
		if (j != m) cout << " ";
	}
	cout << '\n';
//		else if (n <= 5000 && m <= 3000) {
//		for (int i = n; i >= 1; i--) {
//			if (r[a[i]]) continue;
//			r[a[i]] = i;
//		}
//		for (int i = 1; i <= n; i++) {
//			if (l[a[i]]) continue;
//			l[a[i]] = i;
//		}
//		for (int i = 1; i <= m; i++) {
//			int pos = r[a[i]]; // i<=r[a[i]]
//			for (int j = 1; j <= m; j++) {
//				
//			}
//		}
//	}
	return 0;
}
