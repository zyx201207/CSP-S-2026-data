#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
#define rep(i, a, b) for(ll i = (a); i <= (b); i++)
const ll N = 2e5 + 10;
ll n, m;
ll arr[N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	ll maxa = -1;
	rep(i, 1, n) {
		cin >> arr[i];
		maxa = max(maxa, arr[i]);
	}
	sort(arr + 1, arr + 1 + n);
	if(m == 1) return cout << maxa, 0;
	ll maxc = -1;
	rep(j, 1, n - m + 1) {
		ll rs = arr[j];
		rep(i, j + 1, j + m - 1) rs = rs & arr[i];
		maxc = max(maxc, rs); 
	}
	cout << maxc << endl;
	return 0;
}
