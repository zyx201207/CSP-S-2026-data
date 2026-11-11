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
int n;
ll a[N], sum[N], m;

bool check(int l, int r) {return (r - l + 1) * a[r] - (sum[r] - sum[l - 1]) <= m;}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while(l < r) {
			int mid = l + r >> 1;
			if(check(mid, i)) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}

	cout << ans << '\n';
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T--) solve();
	return 0;
}