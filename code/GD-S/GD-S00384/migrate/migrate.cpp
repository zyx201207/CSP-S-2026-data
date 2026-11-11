#include <bits/stdc++.h>
// #define int long long
// #define lson (id << 1)
// #define rson (id << 1 | 1)
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

 constexpr int N = 2e6 + 5;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;

int nx[N];
ll p[N];
int dis[N], tag[N], nowtime;
int dis2[N], tag2[N], nowtime2;
int cnt[N];

int bfs(int s) {
	dis[s] = 0, tag[s] = ++ nowtime;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v = u + 1; v <= nx[u]; v ++) {
			if (tag[v] != nowtime) {
				dis[v] = dis[u] + 1, tag[v] = nowtime;
				q.push(v);
			}
		}
	}
	
	dis2[s] = 0, tag2[s] = ++ nowtime2, cnt[s] = 1;
	q.push(s);
	int res = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v = u + 1; v <= nx[u]; v ++) {
			if (tag2[v] != nowtime2) {
				cnt[v] = 0, tag2[v] = nowtime2;
				dis2[v] = dis2[u] + 1;
				q.push(v);
			}
			if (dis2[u] + 1 == dis[v]) {
				if (cnt[v] == 2) res --;
				cnt[v] += cnt[u];
				if (cnt[v] == 2) res ++;
			}
		}
	}
	return res;
}

void solve() {
	int n; ll d; cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> p[i];
	nx[0] = 1;
	for (int i = 1; i <= n; i ++) {
		nx[i] = nx[i - 1];
		while (nx[i] < n && p[nx[i] + 1] - p[i] <= d) nx[i] ++;
	}
//	cout << "nx:"; for (int i = 1; i <= n; i ++) cout << nx[i] << ' ';
//	cout << endl;
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += bfs(i);
//		printf("s = %d\n", i);
//		for (int j = 1; j <= n; j ++) cout << (tag2[j] == nowtime2 ? cnt[j] : -1) << ' ';
//		cout << endl;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i ++) tag[i] = 0;
}

signed main()
{
//     freopen("input_m3.txt", "r", stdin);
     freopen("migrate.in", "r", stdin);
     freopen("migrate.out", "w", stdout);
     ios::sync_with_stdio(0), cin.tie(0);
    int c, T; cin >> c >> T;
    while (T --) {
    	solve();
	}
    return 0;
}
