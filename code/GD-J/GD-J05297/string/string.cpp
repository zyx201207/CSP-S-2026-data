#include <bits/stdc++.h>
using namespace std; 
#define int long long

int n, a[200010], c[200010];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int x; char y; cin >> x >> y;
		a[i] = x; c[i] = y;
		sum += a[i];
	}
	int h = 1, t = n, ans = 0; // head、tail指针 
	while(true) {
		if(h >= t) break; // 退出条件 
		if(a[h] == a[t]) {
			if(c[h] != c[t]) ans += a[h];
			h++; t--;
		}
		else if(a[h] < a[t]) {
			if(c[h] != c[t]) ans += a[h];
			a[t] -= a[h];
			h++;
		}
		else {
			if(c[h] != c[t]) ans += a[t];
			a[h] -= a[t];
			t--; 
		}
	}
	cout << ans;
	return 0;
}
