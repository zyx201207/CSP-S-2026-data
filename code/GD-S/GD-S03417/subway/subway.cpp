#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 5e2 + 10, M = 5e5 + 10;
int a[N][N], t[N][N], w[M], k[N], x[M], y[M], s[N][N];
int edges[110][10010];
int c, n, m, d, q;
vector <int> g[M];
void solve() {
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			s[i][j] = s[i][j - 1] + t[i][j];
		}
	}
	for(int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	bool flag = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int sq = 1; sq <= k[i]; sq++) {
				for(int s1 = 1; s1 <= k[j]; s1++) {
					if(a[i][sq] == a[j][s1]) {
						g[a[i][sq]].push_back(i);
						g[a[i][sq]].push_back(j);
						flag = 1;
					}
				}
			}
		}
	} 
	int ans = 0;
	for(int it = 1; it <= q; it++) {
		ans += w[x[it]];
		int minn = INT_MAX;
		for(int i = 1; i <= n; i++) {
			int j = 1;
			while(a[i][j] != x[it]) {
				j++;
			}
			int l = j;
			while(a[i][j] == y[it]) {
				j++;
			}
			int r = j;
			minn = min(minn, s[i][r] - s[i][l - 1]);
		}
		ans += minn;
		ans += w[y[it]];
		cout << ans << endl;
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int T = 1;
	while(T--) {
		solve();
	}

	return 0;
}

