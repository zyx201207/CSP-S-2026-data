#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = (int)5e5 + 5, D = 22;
const int _N = N + 5, _M = M + 5, _D = D + 2;
const ll INF = (ll)1e18 + 5;
int n, m, w[_M], k[_N];
vector<int> lne[_M];
ll dis[_N][_N];
map<int, ll> mxt[_N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, d, q; cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k; cin >> k;
		for(int j = 1; j <= k; j++) {
			int a0; cin >> a0; lne[a0].push_back(i);
			cin >> mxt[i][a0];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) continue; 
			dis[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j : lne[i]) {
			for(int k : lne[i]) {
				if(j == k) continue;
				dis[j][k] = min(dis[j][k], mxt[j][i] + mxt[k][i]);
				dis[k][j] = dis[j][k];
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int st = 1; st <= n; st++) {
			for(int ed = 1; ed <= n; ed++) {
				dis[st][ed] = min(dis[st][ed], dis[st][i] + dis[i][ed]);
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		ll ans0 = INF;
		for(int st : lne[x]) {
			for(int ed : lne[y]) {
				ans0 = min(ans0, mxt[st][x] + dis[st][ed] + mxt[ed][y]);
			}
		}
		cout << w[x] + ans0 + w[y] << endl;
	}
	return 0;
} 
