#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int M = 5e5+5;
constexpr int N = 505;
int w[M];
// first one is id, second is the value
vector<pair<int, int> > has[M];
// also, like former
vector<pair<int, int> > line[N];
//bitset<N + M> vis;
ll sub[N][N];
int c, n, m, d, q;
//void dji(const int& bg, const int& ed)
//{
//	memset(dis, 0x3f, sizeof dis);
////	cerr << dis[0] << '\n';
////	assert(dis.size() == m + n + 1);
//	priority_queue<pair<ll, int> > pq;
//	// code: 1~n means on line, n + 1 ~ n + m + 1 means one the station
//	dis[bg + n] = 0;
//	pq.emplace(0, bg + n);
//	while (!pq.empty())
//	{
//		int u = pq.top().second;
//		ll ud = -pq.top().first;
//		pq.pop();
////		if (u > n)
////			cerr << "p:" << u - n << '\n';
////		else cerr << "l:" << u << '\n';
//		if (vis[u])
//			continue;
//		vis[u] = true;
//		if (u == ed + n)
//			break;
//		if (u > n)
//		{
//			u -= n;
//			// don't use dis[u]!!!
//			for (pair<int, int> vw : has[u])
//				if (dis[vw.first] > ud + vw.second)
//				{
//					dis[vw.first] = ud + vw.second;
//					pq.emplace(-dis[vw.first], vw.first);
//				}
//		}
//		else
//		{
//			// no repeat ! and to add n please!
//			for (pair<int, int> vw : line[u])
//				if (!vis[vw.first] && dis[vw.first] > ud + vw.second)
//				{
//					dis[vw.first] = ud + vw.second;
//					pq.emplace(-dis[vw.first], vw.first);
//				}
//		}
//	}
//	assert(vis[ed + n]);
//	vis.reset();
////	cerr << dis[ed + n] << ' ' << w[bg] << ' ' << w[ed] << '\n';
//	cout << dis[ed + n] + w[bg] + w[ed] << '\n';
//}
inline int read()
{
	int w = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	for (; ch >= '0' && ch <= '9'; ch = getchar())
	{
		w = w * 10 + (ch ^ 48);
	}
	return w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
//	dji();
	memset(sub, 0x3f, sizeof sub);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cin >> c >> n >> m >> d >> q;
	c = read(), n = read(), m = read(), d = read(), q = read();
	// another points following
	for (int i = 1; i <= m; i ++)
//		cin >> w[i];
		w[i] = read();
//	cerr << "w input is OK!\n";
	for (int i = 1; i <= n; i ++)
	{
		sub[i][i] = 0;
		int k = read();
//		cin >> k;
		while (k --)
		{
			int a = read(), t = read();
//			cin >> a >> t;
			has[a].emplace_back(i, t);
			line[i].emplace_back(a + n, t);
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		for (pair<int, int> v1 : has[i])
			for (pair<int, int> v2 : has[i])
				if (v1.first != v2.first)
				{
					sub[v2.first][v1.first] = sub[v1.first][v2.first] = min(sub[v1.first][v2.first], 1ll * v1.second + v2.second);
				}
	}
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++)
			for (int k = 1; k <= n; k ++)
				if (k != i && k != j)
					sub[j][i] = sub[i][j] = min(sub[i][j], sub[i][k] + sub[k][j]);
	while (q --)
	{
		int x = read(), y = read();
//		cin >> x >> y;
//		dji(x, y);
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (pair<int, int> vx : has[x])
			for (pair<int, int> vy : has[y])
				ans = min(ans, sub[vx.first][vy.first] + vx.second + vy.second);
		cout << ans + w[x] + w[y] << '\n';
//		write(ans + w[x] + w[y]);
	}
	return 0;
}
