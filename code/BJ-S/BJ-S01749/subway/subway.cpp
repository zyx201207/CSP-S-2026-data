#include <bits/stdc++.h>
using namespace std;
struct fis {
	unsigned pos = 1 << 20;
	char c, buf[1 << 20];
	char &getc() {
		if (pos == (1 << 20)) {
			fread(buf, 1, 1 << 20, stdin);
			pos = 0;
		}
		return c = buf[pos++];
	}
	template<typename T>
	fis &operator>>(T &x) {
		while (getc() < '0' || c > '9') {}
		x = '0' ^ c;
		while (getc() >= '0' && c <= '9') {
			x = (x << 1) + (x << 3) + ('0' ^ c);
		}
		return *this;
	}
} ewin;
#define cin ewin
struct fos {
	unsigned pos;
	char buf[1 << 20];
	void flush() {
		fwrite(buf, 1, pos, stdout);
		pos = 0;
	}
	void putc(char x) {
		if (pos == (1 << 20)) {
			flush();
		}
		buf[pos++] = x;
	}
	template<typename T>
	fos &operator<<(T x) {
		if (x > 9) {
			*this << x / 10;
		}
		putc('0' ^ (x % 10));
		return *this;
	}
} ewout;
#define cout ewout
#define int long long
int n, m, d, q, w[500005], dis[505][505];
vector<pair<int, int> > sub[500005];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1, k, a, t; i <= n; i++) {
		cin >> k;
		while (k--) {
			cin >> a >> t;
			sub[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < sub[i].size(); j++) {
			for (int k = j + 1; k < sub[i].size(); k++) {
				dis[sub[i][j].first][sub[i][k].first] =
				dis[sub[i][k].first][sub[i][j].first] =
				min(dis[sub[i][j].first][sub[i][k].first],
					sub[i][j].second + sub[i][k].second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = dis[0][0];
		for (int i = 0; i < sub[x].size(); i++) {
			for (int j = 0; j < sub[y].size(); j++) {
				ans = min(ans, sub[x][i].second + sub[y][j].second + dis[sub[x][i].first][sub[y][j].first]);
			}
		}
		cout << ans + w[x] + w[y];
		cout.putc('\n');
	}
	cout.flush();
	return 0;
}
