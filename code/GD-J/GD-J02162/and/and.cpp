#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010];
int ans = 0;
void dfs(int u, int s, int c, int sel) {
	if(c == m) {
		ans = max(ans, s);
		return; 
	}
	if(u == n + 1) return;
	dfs(u + 1, (sel == 0 ? a[u] : s & a[u]), c + 1, 1);
	dfs(u + 1, s, c, sel);
}
void solve() {
	sort(a + 1, a + n + 1);
	if(m == 1) {
		ans = a[n]; return;
	}
	if(m == n) {
		ans = a[1];
		for(int i = 2; i <= n; i ++) ans &= a[i];
		return;
	}
	if(m == 2) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(i == j) continue;
				ans = max(ans, a[i] & a[j]);
			}
		}
		return;
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n <= 20) dfs(1, 0, 0, 0);
	else if(n <= 2000) solve();
	else {
		sort(a + 1, a + n + 1);
		ans = a[n];
		for(int i = 1; i <= m; i ++) {
			ans &= a[n - i];
		}
	}
	cout << ans;
	return 0;
}
/*
Once upon a time
Morning glow, scattered lights 
Shone on you and I
In fading poems, frozen rhymes
Our traces on the breeze
Whisper sounds, past reveries
Please let me linger for now
Enveloped in your sound
Love on the pages
The ink of stories penned
No matter how we end
I'll do it all again
OvO
*/
