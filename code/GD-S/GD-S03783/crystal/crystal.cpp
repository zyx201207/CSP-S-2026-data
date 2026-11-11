#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-x))
#define MID(l, r) ((l) + ((r) - (l)) >> 1)
#define ls(p) ((p) << 1)
#define rs(p) ((p) << 1 | 1)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using lf = double;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 1e6 + 10;

ll n, m;
ll a[N];

void Input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	Input();
	
	sort(a + 1, a + n + 1);
	ll used = 0, ans = 0;
	for (int l = 2, r = 1; l <= n; ++l) {
		used += (a[l] - a[l - 1]) * (l - r);
		while (used > m) {
			used -= a[l] - a[r];
			++r;
		}
		ans = max(ans, 1ll * l - r + 1);
	}
	cout << ans;
	
	return 0;
}

