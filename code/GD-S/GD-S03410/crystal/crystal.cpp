#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5; 
ll a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	
	int ans = 0;
	queue<ll> q;
	ll tot = 0;
	int sz = 0;
	for (int i = 1; i <= n; i++) {
		q.push(a[i]);
		tot += a[i];
		sz++;
		ll delta = 1ll * sz * a[i]  - tot;
		while (delta >= m + 1ll) {
			sz--;
			tot -= q.front();
			q.pop();
			delta = 1ll * sz * a[i]  - tot;
		}
		ans = max(ans, sz);
	}
	cout << ans << endl;
	return 0;
} 
