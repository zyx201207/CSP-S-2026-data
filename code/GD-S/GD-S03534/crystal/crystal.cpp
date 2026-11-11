#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

const int N = 5e5 + 10;
ll a[N];
map<ll, ll> cnt;
priority_queue<pll, vector<pll>, greater<pll>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		++cnt[a[i]];
	}
	ll maxn = 0, c = 0, sum = 0, lst = -4e18;
	for (auto p : cnt) {
		ll x = p.first, y = p.second;
		if (lst != -4e18) sum += (x - lst) * c;
		while (sum > m) {
			auto fr = q.top();
			q.pop();
			ll t = x - fr.first;
			ll mi = min(fr.second, (sum - m + t - 1) / t);
			c -= mi;
			sum -= t * mi;
			if (mi < fr.second) q.push({fr.first, fr.second - mi});
		}
		q.push({x, y});
		c += y;
		maxn = max(maxn, c);
		lst = x;
	}
	cout << maxn << '\n'; 
	return 0;
}
