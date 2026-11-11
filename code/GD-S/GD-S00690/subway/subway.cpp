#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1005;
int c, n, m, d, q;
const int maxm = 5e5 + 5;
int w[maxm];
int k[maxm];
struct edge {
	int to, t;
	bool operator <(edge x) {
		return to < x.to;
	}
};
vector<vector<edge>> e;
vector<int> has[maxn];
ll dis[maxn][maxn];
ll search(int x, int fd) {
	int l = 1, r = k[x], mid, ans = -1;
	while (l <= r) {
		mid = l + r >> 1;
		if (e[x][mid].to == fd) return e[x][mid].t;
		if (e[x][mid].to < fd) l = mid + 1, ans = mid;
		else r = mid - 1; 
	}
	cerr << x << ' ' << fd << ' ' << ans << ' ' << l << ' ' << r << "??????\n";
	return e[x][ans].t;
}
void solve1() {
	e.assign(m + 1, {});
	memset(dis, 0x3f, sizeof(dis));
	ll inff = dis[1][1];
	for (int i = 1; i <= n; i++) cin >> w[i];
	int x, ti;
	for (int i = 1; i <= m; i++) {
		cin >> k[i];
		e[i].push_back({0, 0});
		for (int j = 1; j <= k[i]; j++) {
			cin >> x >> ti;
			e[i].push_back({x, ti});
			has[x].push_back(i);
		}
		sort(e[i].begin(), e[i].end());
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int l = 0, r = 0, tmp;
			ll t = 0;
			while (l < has[i].size() && r < has[j].size()) {
				if (has[i][l] < has[j][r]) l++;
				else if (has[i][l] > has[j][r]) r++;
				else {
					tmp = has[i][l];
					dis[i][j] = dis[j][i] = min(dis[i][j], search(tmp, i) + search(tmp, j));
//					cout << i << ' ' << j << ' ' << l << ' ' << r << endl;
					l++, r++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dis[i][k] != inff && dis[j][k] != inff) 
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << (dis[i][j] == inff ? -1 : dis[i][j]) <<' ';
//		}
//		cout << endl;
//	} 
	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << dis[l][r] + w[l] + w[r] << '\n';
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> m >> n >> d >> q;	
	
	solve1();
}
