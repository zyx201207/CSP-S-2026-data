#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//100f O(n log n)
const int maxn = 5e5 + 5;
const ll inf = 1e18 + 5;

ll n, m;
ll a[maxn];
ll ljq[maxn];

bool check(ll mid) {
	ll sum = inf;
	for (int i = 1; i + mid - 1 <= n; i++) {
		ll LJQ = 1ll * mid * a[i + mid - 1] - (ljq[i + mid - 1] - ljq[i - 1]);
		sum = min(sum, LJQ);
	}
	if (sum > m) return 0;
	else return 1;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) ljq[i] = ljq[i - 1] + a[i];
	ll l = 1, r = n + 1;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}  
