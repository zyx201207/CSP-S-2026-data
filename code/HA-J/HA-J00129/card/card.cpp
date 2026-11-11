#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

#define N 500005
#define M 300005

unordered_map<ll, ll> mp;
ll n, m, a[N];
vector<int> d;
ll flag = 1, ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) flag = 0;
	}
	
	if (flag) {
		for (ll i = 1; i <= n; i++) {
			mp[a[i]]++;
		}
		for (ll i = 1, sum = 0; i <= m; i++) {
			sum += mp[i];
			cout << sum << " \n"[i == m];
		}
		
		return 0;
	}
	
	for (ll i = 1; i <= n; i++) {
		d.clear(), mp.clear();
		for (ll j = i; j <= n; j++) {
			if (mp[a[j]]) {
				while (d.back() != a[j] && d.size()) {
					mp[d.back()] = 0;
					d.pop_back();
				}
				mp[a[j]] = 1;
			} else {
				d.push_back(a[j]);
				mp[a[j]] = 1;
			}
		}
		for (int j = 1; j <= m; j++) ans[j] += mp[j];
//		cerr << mp[3] << "\n";
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];

	return 0;
}

