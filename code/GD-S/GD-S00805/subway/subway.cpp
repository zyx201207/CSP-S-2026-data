#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long w[500005], k[505], a[500005], t[500005], x, y;
struct node {
	long long v, w;
}; 
vector<node> H[500005];
long long f[1005][1005];

signed main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		cin >> k[i];
		for (long long j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
			H[a[j]].push_back({i, t[j]});
		}
	}
	memset(f, 0x3f, sizeof f);
	for (long long i = 1; i <= m; i++) {
		for (long long j = 0; j < H[i].size(); j++) {
			for (long long k = 0; k < H[i].size(); k++) {
				if (j == k) continue;
				long long w1 = H[i][j].w;
				long long w2 = H[i][k].w;
				long long v1 = H[i][j].v;
				long long v2 = H[i][k].v;
				f[v1][v2] = f[v2][v1] = min(f[v1][v2], w1 + w2);
			}
		}
	}
	for (long long k = 1; k <= n; k++) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				f[i][j] = f[j][i] = min(f[i][k] + f[k][j], f[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)f[i][i] = 0;
	for (long long i = 1; i <= q; i++) {
		cin >> x >> y;
		long long ans = 1e17;
		for (long long j = 0; j < H[x].size(); j++) {
			for (long long k = 0; k < H[y].size(); k++) {
				long long v1 = H[x][j].v;
				long long v2 = H[y][k].v;
				long long w1 = H[x][j].w;
				long long w2 = H[y][k].w;
//				cout << v1 << " " << v2 << ":" << f[v1][v2] << endl;
				ans = min(ans, f[v1][v2] + w1 + w2);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
