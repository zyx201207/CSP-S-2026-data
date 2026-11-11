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

constexpr int N = 1e6 + 10;
int TEST_ID, n, m;
vector<int> e[N];

namespace Case1 {
	namespace DSU {
		int cnt, fa[N], siz[N];
		void init() {
			cnt = n;
			for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
		}
		int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
		void unify(int u, int v) {
			u = find(u), v = find(v);
			if(u == v) return;
			cnt--;
			if(siz[u] > siz[v]) swap(u, v);
			fa[u] = v, siz[v] += siz[u];
		}
	}

	bool sel[N];
	bool check() {
		DSU::init();
		for(int u = 1; u <= n; u++) {
			if(!sel[u]) continue;
			for(auto v : e[u]) if(sel[v]) DSU::unify(u, v);
		}
		return DSU::cnt <= n - m + 2;
	}

	int dis[N];
	int bfs() {
		fill(dis + 1, dis + n + 1, -1);
		queue<int> q;
		for(int i = 1; i <= n; i++) {
			if(!sel[i]) continue;
			dis[i] = 0;
			q.push(i);
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v : e[u]) {
				if(~dis[v]) continue;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		return *max_element(dis + 1, dis + n + 1);
	}

	int ans;
	void getans(int x, int cnt) {
		if(cnt > m) return;
		if(n - x + 1 < m - cnt) return;
		if(cnt == m) {
			if(check()) ans = min(ans, bfs());
			return;
		}
		sel[x] = 1;
		getans(x + 1, cnt + 1);
		sel[x] = 0;
		getans(x + 1, cnt);
	}

	void solve() {
		ans = 1e9;
		fill(sel + 1, sel + n + 1, 0);
		getans(1, 0);
		cout << ans << '\n';
	}
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	Case1::solve();
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> TEST_ID >> T;
	while(T--) solve();
	return 0;
}