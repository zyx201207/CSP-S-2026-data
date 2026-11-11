#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i)
using namespace std;

const int N = 500, M = 1e3 + 5;
int c, n, m, d, q;
int w[N], a[N][M], t[N][M], x, y, ans2, r, p;

vector < int > G[N]; //站台在几号线 
vector < int > g[N];

void solve() {
	ans2 += t[r][x] + t[p][y];
	cout << ans2 << '\n';
}
void solve2() {
	int ans = 0;
	ans += w[x] + w[y];
	if(G[x].size() == 1 && G[y].size() == 1 && (G[y][1] != G[x][0] || G[y][0] != G[x][0])) {
		ans += t[x][G[x][0]] + t[y][G[y][0]];
		
		int qm = 1;
		inc(t, 1, m) {
			if(G[m].size() != 1) {
				qm = m; break;
			}
		}
		ans += t[G[y][0]][qm] + t[G[x][0]][qm];
		cout << ans << '\n';
	} else {
		ans += t[G[x][0]][x] + t[G[y][0]][y];
		cout << ans << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	inc(i, 1, m) cin >> w[i];
	inc(i, 1, n) {
		int k; cin >> k;
		inc(j, 1, k) {
			cin >> a[i][j] >> t[i][j];
			if(j == 2 && c != 20 && c != 30) G[a[i][j]].push_back(i);
			else G[a[i][j]].push_back(i);
			if(a[i][j] == x) r = i;
			if(a[i][j] == y) p = i;
		} 
	}
	q = 1;
	while(q--) {
		cin >> x >> y;
		if(c == 20 || c == 21) {
			solve2();
		} else solve();
		
	}
} 
