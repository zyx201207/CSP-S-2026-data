#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
int dis[505][505], c, n, m, d, q, w[maxn];
vector<pair<int, int> > vec[maxn];
vector<int> qry[maxn]; int x[maxn], y[maxn];
int ans[maxn];
int query(int x, int y) {
	int ans = 9e18;
	for (int xt = 0; xt < vec[x].size(); xt++)
		for (int yt = 0; yt < vec[y].size(); yt++) {
			int xp = vec[x][xt].first, yp = vec[y][yt].first;
			ans = min(ans, w[x] + w[y] + vec[x][xt].second + vec[y][yt].second + dis[xp][yp]);
		}
	return ans;
}
int Read() {
	int sum = 0, f = 1; char c = getchar();
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c))
		sum = sum * 10 + c - '0', c = getchar();
	return sum * f;
}
void Write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x <= 9) {
		putchar(x + '0');
		return ;
	}
	Write(x / 10); putchar(x % 10 + '0');
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = Read(), n = Read(), m = Read(), d = Read(), q = Read();
	for (int i = 1; i <= m; i++)
		w[i] = Read();
	for (int i = 1; i <= n; i++) {
		int k = Read();
		while(k--) {
			int x, t; x = Read(); t = Read();
			vec[x].push_back(make_pair(i, t));
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
//		cout <<
		for (int j = 0; j < vec[i].size(); j++) {
			pair<int, int> p = vec[i][j];
			for (int k = 0; k < vec[i].size(); k++) {
				pair<int, int> q = vec[i][k];
				dis[p.first][q.first] = min(dis[p.first][q.first], p.second + q.second);
//				cout << p.first << " " << q.first << endl;
			}
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cout << dis[i][j] << (j == n ? '\n' : ' ');
	for (int i = 1; i <= q; i++)
		x[i] = Read(), y[i] = Read(), Write(query(x[i], y[i])), putchar('\n');
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
} 
