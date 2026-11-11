#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, m, a[N], abss[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int mx = 0;
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] > a[i]) abss[j] = m + 1;
			else abss[j] = abs(a[i] - a[j]);
		} 
		sort(abss + 1, abss + 1 + n);
		for(int j = 1; j <= n; j++) {
			if(mx > m) break;
			mx += abss[j];
			cnt++; 
		}
		ans = max(cnt - 1, ans);
	} 
	cout << ans;
	return 0;
}
/*

5 8 
-3 -1 2 2 7

5 5 
1 2 4 8 9

*/
