#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5, inf = 1LL << 60;
long long c, T, n, d, ans;
int x[2000005], f[N], s[N];
struct Seg_Tree{
	struct Node{
		int l, r;
		int dat;
	} t[N << 2];
	#define ls (u << 1)
	#define rs (u << 1 | 1)
	void build(int u, int l, int r){
		t[u] = {l, r, 0};
		if(l == r) return;
		int mid = (l + r) >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void update(int u, int x, int k){
		if(t[u].l == t[u].r){t[u].dat = k; return;}
		int mid = (t[u].l + t[u].r) >> 1;
		if(x <= mid) update(ls, x, k);
		else update(rs, x, k);
		t[u].dat = min(t[ls].dat, t[rs].dat);
	}
	int query(int u, int L, int R){
		if(L <= t[u].l && t[u].r <= R) return t[u].dat;
		int mid = (t[u].l + t[u].r) >> 1, res = inf;
		if(L <= mid) res = min(res, query(ls, L, R));
		if(R > mid) res = min(res, query(rs, L, R));
		return res;
	}
} t_min;
int now;
struct BIT{
	int c[N], t[N];
	int lowbit(int x){return x & -x;}
	void update(int x, int k){
		while(x < N){
			if(t[x] != now) c[x] = 0, t[x] = now;
			c[x] += k, x += lowbit(x);
		}
	}
	int query(int x){
		int s = 0;
		while(x){
			if(t[x] != now) c[x] = 0, t[x] = now;
			s += c[x], x -= lowbit(x);
		}
		return s;
	}
	int query(int l, int r){return query(r) - query(l - 1);}
} t_sum[N];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	for(cin >> c >> T; T --> 0;){
		cin >> n >> d; ans = 0;
		for(int i=1; i<=n; i++) cin >> x[i];
		t_min.build(1, 1, n);
		for(int i=1; i<=n; i++){
			f[i] = 1, s[i] = 0, now++;
			t_sum[0].update(i, 1);
			t_min.update(1, i, 0);
			for(int j=i+1, k=i; j<=n; j++){
				while(x[j] - x[k] > d) k++;
				int mi = t_min.query(1, k, j - 1);
				f[j] = t_sum[mi].query(k, j - 1);
				t_min.update(1, j, s[j] = mi + 1);
				t_sum[s[j]].update(j, f[j]);
				if(f[j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
