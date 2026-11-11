// GZ-S00091 »Æ¼ÑÂå »ªÊ¦Ò»¹óÑô 
#include <bits/stdc++.h>
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define iv inline void
#define it inline int
#define pb push_back
#define LL long long
#define PII pair<int, int>
#define x first
#define y second
#define PIII pair<int, PII>

using namespace std;

const int N = 3e6 + 10, M = 55;

int c, n, m, q, d;
int dist[M][M];
bool st[M][M][M][M];
int k[N], a[M][M], t[M][M], w[N];

void dfs(int ss, int u, int tt, int d, int lst, bool tm) {
	if (st[u][tt][ss][lst]) return ;
	st[u][tt][ss][lst] = 1; 
//	cout << ss << ' ' << tt << ' ' << u << ' ' << d << endl; 
	if (tt == u) return dist[ss][tt] = min(dist[ss][tt], d), void();
	upp(i, 1, n) upp(j, 1, k[i]) {
		if (u == a[i][j]) {
			if (i != lst && lst) {
				dfs(ss, u, tt, d, i, tm);
			}
			else {
				upp(q, 1, k[i]) {
					if (j != q) dfs(ss, a[i][q], tt, d + t[i][j] + t[i][q], i, tm);
				}
			}
			
		}
	}
}

signed main() {
	 freopen("subway.in", "r", stdin);
	 freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	upp(i, 1, m) cin >> w[i];
	upp(i, 1, n) {
		cin >> k[i];
		upp(j, 1, k[i]) cin >> a[i][j] >> t[i][j];
	}
	memset(dist, 0x3f, sizeof dist);
	upp(i, 1, m) upp(j, 1, m) if (i != j) dfs(i, i, j, 0, 0, 0), dist[i][j] += w[i] + w[j];
	while (q--) {
		int a, b; cin >> a >> b;
		cout << dist[a][b] << endl;
	}
	return 0;
}
