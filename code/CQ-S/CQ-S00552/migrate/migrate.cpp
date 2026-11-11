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

constexpr int N = 2e6 + 10;
int TEST_ID, n;
ll a[N], m;

namespace Case {
	int l[N], r[N], dis[N], cnt[N];

	void bfs(int src) {
		fill(dis + 1, dis + n + 1, -1);
		fill(cnt + 1, cnt + n + 1, 0);
		dis[src] = 0, cnt[src] = 1;
		queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v = l[u]; v <= r[u]; v++) {
				if(!~dis[v]) {
					dis[v] = dis[u] + 1, cnt[v] = cnt[u];
					q.push(v);
				}
				else if(dis[v] == dis[u] + 1) {
					cnt[v] += cnt[u];
					if(cnt[v] >= 3) cnt[v] = 3;
				}
			}
		}
	}

	void solve() {
		for(int i = 1; i <= n; i++) {
			l[i] = lower_bound(a + 1, a + n + 1, a[i] - m) - a;
			r[i] = upper_bound(a + 1, a + n + 1, a[i] + m) - a - 1;
		}

		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			bfs(i);
			for(int j = 1; j < i; j++)
				if(cnt[j] == 2) ans++;
		}
		cout << ans << '\n';
	}
}

namespace CaseA {
	void solve() {
		ll d = a[2] - a[1];
		int len = min((ll)n - 1, m / d);
		cout << (len > 1 ? max(0, n - (len << 1) + 1) : 0) << '\n';
	}
}

namespace CaseB {
	int getcnt(ll l, ll r) {return max(0, (int)(upper_bound(a + 1, a + n + 1, r) - lower_bound(a + 1, a + n + 1, l)));}

	void solve() {
		ll ans = 0;
		for(int v = 1, u1 = 1, u2 = 0, u = 0; v <= n; v++) {
			while(u1 <= n && getcnt(a[v] - m, a[u1] + m) <= 1) u1++;
			while(u2 < n && getcnt(a[v] - m, a[u2 + 1] + m) < 3) u2++;
			while(u < n && a[u + 1] < a[v] - m) u++;
			ans += max(0, min(u, u2) - u1 + 1);
		}
		cout << ans << '\n';
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(TEST_ID >= 11 && TEST_ID <= 12) CaseA::solve();
	else if(TEST_ID >= 13 && TEST_ID <= 14) CaseB::solve();
	else Case::solve();
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> TEST_ID >> T;
	while(T--) solve();
	return 0;
}