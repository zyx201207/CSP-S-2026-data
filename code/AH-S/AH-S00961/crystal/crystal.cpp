#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 500005;

ll a[N], pre[N];
int l;

inline ll calc(int i) {
	return 1ll * (i - l + 1) * a[i] - (pre[i] - pre[l - 1]);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
		
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	l = 1;
	for (int i = 1; i <= n; i++) {
		while (calc(i) > m) {
			l++;
		}
		
		ans = max(ans, i - l + 1);
		
//		assert(calc(i) <= m);
//		
//		assert(l >= 1 && l <= n);
//		assert(r >= 1 && r <= n); 
	}
	
	cout << ans << "\n";
	
	return 0;
}
