#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
using namespace std;
const int maxn = 5e5 + 10;
const int inf = INT_MAX / 2;

ll n, m;
ll a[maxn], mxd = -inf;
bool dengcha = true;
bool xiangdeng = true;

bool check (ll k, ll d) {
	if (d * k * (k - 1) <= 2 * m) return 1;
	else return 0;
}

ll baoli () {
	if (xiangdeng) return n;
	if (mxd > m) return 1;
	if (dengcha) {
		ll l = 0, r = n;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (l == r) return l - 1;
			if (check(mid, a[2] - a[1])) {
				l = mid + 1;
			}else r = mid;
		}
		
	}
	ll res = m, ans = 0, mx = -inf;
	for (int i = 1; i <= n; i++) {
		res = m, ans = 0;
		for (int j = i; j >= 1; j--) {
			int tmp = a[i] - a[j];
			if (res >= tmp) res -= tmp, ans++;
		}
		mx = max(mx, ans);
	}
	return mx;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
    cin >> n >> m; 
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
    }
	for (int i = 1; i < n; i++) mxd = min(mxd, a[i + 1] - a[i]);
    for (int i = 3; i <= n; i++){
		if (a[i - 1] != a[i] && a[i - 2] != a[i - 1]) xiangdeng = false;
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) dengcha = false;
	}
    
	sort (a + 1, a + n + 1);

	cout << baoli();
    
	return 0;
}
