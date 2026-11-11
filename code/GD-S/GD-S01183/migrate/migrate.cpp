#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e16 + 7;
const int N = 2e6 + 7;

int cid, n;
ll x[N], m, ans;

// 300

namespace sub1 {
	const int MAXN = 300 + 7;
	ll f[MAXN], g[MAXN];
	void solve(int L, int R) {
//		cout << L << " " << R << endl;
		for(int i = L; i <= R; i++) {
			f[i] = 0, g[i] = 1;
//			cout << "i: " << i << endl;
			for(int j = i + 1; j <= R; j++) {
				ll minn = inf, sol = 1;
				for(int k = i; k < j; k++) {
					if(x[j] - x[k] <= m) {
						if(f[k] < minn) {
							minn = f[k];
							sol = g[k];
						} else if(f[k] == minn)
							sol += g[k];
					}
				}
				if(sol > 2) sol = 3;
				f[j] = minn + 1, g[j] = sol;
				if(g[j] == 2) ++ans;
//				if(g[j] == 2) cout << i << " " << j << endl;
//				cout << g[j] << " " ;
			}
//			cout << endl;
		}
	}
	void _main_() {
		int lst = 1;
		for(int i = 2; i <= n; i++) {
			if(x[i] - x[i - 1] > m) {
				solve(lst, i - 1);
				lst = i;
			}
		}
		solve(lst, n);
		cout << ans << "\n";
	}
} ;

//5000

namespace sub2 {
	const int MAXN = 5e3 + 7;
	ll f[MAXN], g[MAXN];
	struct tree {
		ll val, cnt;
	} tr[MAXN << 2];
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	void pushup(int p) {
		if(tr[ls].val < tr[rs].val) {
			tr[p] = tr[ls];
		} else if(tr[ls].val > tr[rs].val) {
			tr[p] = tr[rs];
		} else {
			tr[p] = {tr[ls].val, min(tr[ls].cnt + tr[rs].cnt, 3ll)};
		}
	}
	void build(int l, int r, int p) {
		if(l == r) {
			tr[p] = {inf, 0};
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		pushup(p);
	}
	void change(int s, int t, int p, int x, tree k) {
		if(s == t) {
			tr[p] = k;
			return ;
		}
		int mid = (s + t) >> 1;
		if(x <= mid) change(s, mid, ls, x, k);
		else change(mid + 1, t, rs, x, k);
		pushup(p);
	}
	void solve(int L, int R) {
		for(int i = L; i <= R; i++) {
			f[i] = 0, g[i] = 1;
			build(i, R, 1);
			change(i, R, 1, i, {f[i], g[i]});
			for(int j = i + 1, hd = i; j <= R; j++) {
				while(hd < j and x[hd] + m < x[j]) {
					change(i, R, 1, hd, (tree){inf, 0});
					++hd;
				}
				ll minn = tr[1].val, sol = tr[1].cnt;
				if(sol > 2) sol = 3;
				f[j] = minn + 1, g[j] = sol;
//				cout << i << " " << j << " " << hd << " " << f[j] << " " << g[j] << endl;
				change(i, R, 1, j, (tree){f[j], g[j]});
				if(g[j] == 2) ++ans;
//				cout << g[j] << " " ;
			}
//			cout << endl;
		}
	}
	void _main_() {
		int lst = 1;
		for(int i = 2; i <= n; i++) {
			if(x[i] - x[i - 1] > m) {
				solve(lst, i - 1);
				lst = i;
			}
		}
		solve(lst, n);
		cout << ans << "\n";
	}
} ;

// A

namespace sub3 {
	void _main_() {
		ll c = x[2] - x[1];
		ll d = m / c;
		if(d <= 1) {
			cout << 0 << "\n";
			return ;
		} else {
			cout << max(0ll, n - 2 * (d - 1) - 1) << "\n";
		}
	}
} ;

void work() {
	ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if(n <= 300) {
		sub1::_main_();
		return ;
	} else if(n <= 5000) {
		sub2::_main_();
		return ;
	}
	int sm = 0, dif = x[2] - x[1];
	for(int i = 2; i < n; i++) {
		if(dif ^ (x[i + 1] - x[i])) {
			sm = 1;
			break;
		}
	}
	if(!sm) {
		sub3::_main_();
		return ;
	}
//	for(int i = 1; i < n; i++) {
//		cout << x[i + 1] - x[i] << " "; 
//	} cout << endl;
	cout << ans << "\n";
}

int main() {
//	migrate
//	system("fc migrate.out migrate3.ans"); return 0;
//	freopen("migrate3.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> cid; int _; cin >> _;
	while(_--) work();
	return 0;
}
