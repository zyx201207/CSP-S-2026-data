#include<bits/stdc++.h>

using namespace std;
//bool ST;
#define ll long long
const int maxn = 5e5 + 5;
ll a[maxn], pre[maxn];
void coder() {
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}
	ll ans = 1, l = 1, r = 1;
	while (r <= n) {
		while (r <= n && a[r] * (r - l + 1) - (pre[r] - pre[l - 1]) <= m) {
			++r;
		}
		ans = max(ans, r - l);
		++l;
	}
	cout << ans;
}


//bool ED;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	cerr << (fabs(&ST - &ED) / 1024.0 / 1024.0) << "MB\n";
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	coder();
	
	return 0;
}
