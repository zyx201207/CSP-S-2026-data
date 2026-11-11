#include <iostream>
#define int long long
using namespace std;
const int N = 1e6 + 10, inf = 2e18;
int le[N], ri[N], T, n, d, X[N], Ans, c;
struct node{
	int mi, sum;
}sum[N << 2], f[N];
void clear() {
	Ans = 0;
	for(int i = 1; i <= n; i ++) f[i] = {inf, 0}, le[i] = ri[i] = 0;
}
node Min(node x, node y) {
	if(x.mi < y.mi) return x;
	if(x.mi > y.mi) return y;
	x.sum += y.sum;
	return x;
}
void build(int p, int l, int r) {
	if(l == r) return sum[p] = {inf, 0}, void();
	int mid = l + r >> 1;
	build(p << 1, l, mid);build(p << 1 | 1, mid + 1, r);
	sum[p] = Min(sum[p << 1], sum[p << 1 | 1]);
}
void insert(int p, int l, int r, int x, node k) {
	if(l == r) return sum[p] = k, void();
	int mid = l + r >> 1;
	if(x <= mid) insert(p << 1, l, mid, x, k);
	else insert(p << 1 | 1, mid + 1, r, x, k);
	sum[p] = Min(sum[p << 1], sum[p << 1 | 1]);
}
node query(int p, int l, int r, int x, int y) {
	if(x <= l && y >= r) return sum[p];
	int mid = l + r >> 1;
	node an = {inf, 0};
	if(x <= mid) an = Min(an, query(p << 1, l, mid, x, y));
	if(y > mid) an = Min(an, query(p << 1 | 1, mid + 1, r, x, y));
	return an;
}
signed main() {
//	freopen("D:\\P.in", "r", stdin);
//	freopen("D:\\P.out", "w", stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin >> c >> T;
	while(T --) {
		cin >> n >> d;
		clear();
		for(int i = 1; i <= n; i ++) cin >> X[i];
		int lst = 1;
		for(int i = 1; i <= n; i ++) {
			while(X[i] - X[lst] > d && lst < i) lst ++;
			le[i] = lst;
		}
		lst = n;
		for(int i = n; i >= 1; i --) {
			while(X[lst] - X[i] > d && lst > i) lst --;
			ri[i] = lst;
		}
		if(c <= 10) {
			for(int i = 1; i <= n; i ++) {
				build(1, 1, n);
				f[i] = {0, 1};
				insert(1, 1, n, i, f[1]);
				for(int j = i + 1; j <= n; j ++) {
					f[j] = query(1, 1, n, le[j], j - 1);
					f[j].mi ++;
					insert(1, 1, n, j, f[j]);
				}
				for(int j = i + 1; j <= n; j ++) 
					if(f[j].sum == 2) 
						Ans ++;
			}
			cout << Ans << '\n';	
		}else if(c == 11 || c == 12) {
			if(ri[1] == 1 || ri[1] == 2) {
				cout << 0 << '\n';
				continue;
			}
			int len = ri[1] + ri[1] - 1;
			for(int i = 1; i <= n; i ++) {
				if(i + len - 2 <= n) Ans ++;
			}
			cout << Ans << '\n';
		}
	}
	return 0;
}
 
