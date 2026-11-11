//t1 rp += inf
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 5e5 + 10;
ll n, m, a[N];
queue<ll> q;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ll sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll c = a[i] - a[i-1];
		sum += q.size() * c;
		while (q.size() && sum > m) {
			ll tp = q.front();
			sum -= a[i] - tp;
			q.pop();
		}
		q.push(a[i]);
		ans = max(ans, (ll)q.size());
	}
	cout << ans << '\n';
	return 0;
} 
