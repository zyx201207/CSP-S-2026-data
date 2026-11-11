#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n; ll m;
	cin >> n >> m;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		long long x; cin >> x;
		a[i] = x + 1e12;
	}
	sort(a.begin() + 1, a.end());
	
	int l = 1, ans = 0;
	ll now = 0;
	for(int i = 1; i <= n; ++i) {
		now += a[i];
		while((ll)(i - l + 1) * a[i] - now > m) {
			now -= a[l];
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
} 
