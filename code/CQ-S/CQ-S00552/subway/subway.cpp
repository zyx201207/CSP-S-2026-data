#include<bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define fr first
#define sc second
#define mkp make_pair
using ll = long long;
using db = double;
using pii = pair<int, int>;

const int MOD = 998244353;
struct modint {
	int val;
	modint() : val(0) {}
	modint(ll _val) {
		val = _val <= -MOD || _val >= MOD ? _val % MOD : _val;
		if(val < 0) val += MOD;
	}

	friend istream& operator >>(istream& is, modint& x) {
		ll val;
		is >> val;
		x = val;
		return is;
	}
	friend ostream& operator <<(ostream& os, const modint& x) {
		os << x.val;
		return os;
	}

	modint& operator +=(const modint& x) {
		val += x.val;
		if(val >= MOD) val -= MOD;
		return *this;
	}
	modint operator +(const modint& x)const {
		return modint(*this) += x;
	}

	modint& operator -=(const modint& x) {
		val -= x.val;
		if(val < 0) val += MOD;
		return *this;
	}
	modint operator -(const modint& x)const {
		return modint(*this) -= x;
	}

	modint& operator *=(const modint& x) {
		ll tmp = 1ll * val * x.val;
		val = tmp >= MOD ? tmp % MOD : tmp;
		return *this;
	}
	modint operator *(const modint& x)const {
		return modint(*this) *= x;
	}

	modint power(ll b)const {
		modint a(*this), res(1);
		while(b) {
			if(b & 1) res *= a;
			b >>= 1, a *= a;
		}
		return res;
	}

	modint& operator /=(const modint& x) {
		this->operator*=(x.power(MOD - 2));
		return *this;
	}
	modint operator /(const modint& x)const {
		return modint(*this) /= x;
	}
};
modint qpow(modint a, ll b) {return a.power(b);}

constexpr int N = 5e5 + 10;
int TEST_ID, n, m, lim, q, a[N];
ll dis[510][510];
vector<pii> line[N];

void solve() {
	cin >> TEST_ID >> n >> m >> lim >> q;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		int tot;
		cin >> tot;
		while(tot--) {
			int u, t;
			cin >> u >> t;
			line[u].push_back({i, t});
		}
	}

	for(int i = 1; i <= n; i++) {
		fill(dis[i] + 1, dis[i] + n + 1, 1e18);
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		for(auto tmp1 : line[i]) {
			int id1 = tmp1.fr, t1 = tmp1.sc;
			for(auto tmp2 : line[i]) {
				int id2 = tmp2.fr, t2 = tmp2.sc;
				dis[id1][id2] = min(dis[id1][id2], (ll)t1 + t2);
				dis[id2][id1] = min(dis[id2][id1], (ll)t1 + t2);
			}
		}
	}

	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}

	while(q--) {
		int s, t;
		cin >> s >> t;
		ll ans = 1e18;
		for(auto tmp1 : line[s]) {
			int id1 = tmp1.fr, t1 = tmp1.sc;
			for(auto tmp2 : line[t]) {
				int id2 = tmp2.fr, t2 = tmp2.sc;
				ans = min(ans, dis[id1][id2] + t1 + t2);
			}
		}
		cout << ans + a[s] + a[t] << '\n';
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T--) solve();
	return 0;
}