#include <iostream>
#define int long long
using namespace std;
const int maxn = 10;
int a[maxn], w[maxn], lzy[maxn];
void pushup(int u){
	w[u] = w[u * 2] + w[u * 2 + 1]; 
}
void build(int u, int L, int R){
	if(L == R){
		w[u] = a[L];
		return;
	}
	int M = (L + R) >> 1;
	build(u * 2, L, M);
	build(u * 2 + 1, M + 1, R);
	pushup(u);
}
void maketag(int u, int len, int k){
	lzy[u] += k;
	w[u] += len * k;
}
void pushdown(int u, int L, int R){
	int M = (L + R) >> 1;
	maketag(u * 2, M - L + 1, lzy[u]);
	maketag(u * 2 + 1, R - M, lzy[u]);
	lzy[u] = 0;
}
int query(int u, int L, int R, int l, int r){
	if(l <= L && R <= r) return w[u];
	if(l > R || r < L) return 0;
	pushdown(u, L, R);
	int M = (L + R) >> 1;
	return query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r);
}
void update(int u, int L, int R, int l, int r, int k){
	if(l <= L && R <= r) {
		maketag(u, R - L + 1, k);
		return;
	}
	if(l > R || r < L) return;
	pushdown(u, L, R);
	int M = (L + R) >> 1;
	update(u * 2, L, M, l, r, k);
	update(u * 2 + 1, M + 1, R, l, r, k);
	pushup(u);
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k, sumu = 0, sumv = 0;
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			sumu += u, sumv += v;
		}
		sumu = sumu / n;
		sumv = sumv / n;
		cout << max(sumu / sumv, sumv / sumu) << '\n';
	}
	return 0;
}
