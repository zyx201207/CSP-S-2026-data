#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N], p[N];
int erfen(int l, int r, int y, long long x) {
	while(l <= r) {
		int mid = l + r >> 1;
//		if(y == 3844) cout << mid << " " << x << " " << p[y - mid] << " " << p[y] << " yy\n";
		if(x * mid - (p[y - mid] - p[y]) <= m) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n; cin >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0; 
	for(int i = n; i >= 1; i--) p[i] = p[i + 1]  + a[i]; 
	for(int i = 1; i <= n; i++) {
		int j = i;
		while(j + 1 <= n && a[j + 1] == a[i]) j++;
		int cnt = j - i + 1;
		int k = erfen(0, i - 1, i, a[i]);
//		if(cnt + k == 3845) {
//			cout << i << " " << j << " " << a[i] << "\n";
//		}
//		cout << i << " " << j << " " << k << "\n";
		ans = max(ans, cnt + k);
	}
	cout << ans << "\n";
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
