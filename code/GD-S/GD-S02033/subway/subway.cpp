#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
struct node {int v, w;};
int w[N];
vector<node> vec[N]; 
int f[510][510];
bool duan[510][510];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++) {
		int k; cin >> k;
		for(int j = 1;j <= k;j ++) {
			int v, w; cin >> v >> w;
			vec[v].push_back({m + i, w});
		}
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			f[i][j] = 9100000000000;
		}
	}
	for(int i = 1;i <= n;i ++) f[i][i] = 0;
	for(int i = 1;i <= m;i ++) {
		for(auto u : vec[i]) {
			for(auto v : vec[i]) {
				if(u.v == v.v) continue;
				f[u.v - m][v.v - m] = min(f[u.v - m][v.v - m], u.w + v.w);
				f[v.v - m][u.v - m] = min(f[v.v - m][u.v - m], u.w + v.w);
			}
		}
	}
//	for(int i = 1;i <= n;i ++) {
//		for(int j = 1;j <= n;j ++) {
//			cout << f[i][j] << " ";
//		} cout << endl;
//	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			if(i == j) continue;
			for(int k = 1;k <= n;k ++) {
				if(i == k || j == k) continue;
				if(f[i][k] + f[k][j] < f[i][j]) {
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
//	for(int i = 1;i <= n;i ++) {
//		for(int j = 1;j <= n;j ++) {
//			cout << f[i][j] << " ";
//		} cout << endl;
//	}
	while(q --) {
		int ans = 0, x, y; cin >> x >> y;
		ans += w[x]; ans += w[y];
		int sum = LLONG_MAX;
		for(auto u : vec[x]) {
			for(auto v : vec[y]) {
				sum = min(sum, f[u.v - m][v.v - m] + u.w + v.w);
			}
		}
		cout << ans + sum << endl;
	}
	return 0;
}
