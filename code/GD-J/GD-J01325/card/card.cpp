#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 5e5 + 5;
const ll MAXM = 3e5 + 5;
ll n, m, a[MAXN], ans[MAXN];
ostringstream out;
ll pos[MAXN];
vector<ll> v;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (ll rd = 1; rd <= n; rd++) {
		fill(pos + 1, pos + n + 1, 0);
		v.clear();
		for (ll i = rd; i <= n; i++) {
			if (pos[a[i]]) {
//				cout << a[i] << " appears again! Cleared from " << pos[a[i]] << " to " << v.size() << "." << endl;
				auto it = v.begin() + pos[a[i]] - 1;
				v.erase(it);
//				cout << pos[a[i]] - 1 << endl;
				for (ll j = pos[a[i]] - 1; j < v.size(); j++) {
					pos[v[j]] = 0;
				}
				pos[a[i]] = 0;
			}
			v.push_back(a[i]);
			pos[a[i]] = v.size();
		}
		for (ll i = 1; i <= m; i++) {
			if (pos[i] > 0) ans[i]++;
		}
//		cout << endl;
	}
	
	out.clear();
	for (ll i = 1; i <= m; i++) {
		out << ans[i] << " ";
	}
	cout << out.str() << endl;
	return 0;
}

