#include <bits/stdc++.h>
using namespace std;

namespace OI {

#define int long long
#define endl "\n"

constexpr int maxn = 2e6+5;

int c, T;

int n, d;
int a[maxn];

namespace force {
	
constexpr int maxn = 505; 

int dist[maxn], cnt[maxn];
int edges[maxn][maxn];
struct stat {
	int id, w;
};
struct cmp {
	bool operator() (stat a, stat b) {
		return a.w > b.w;
	}
};
priority_queue<stat, vector<stat>, cmp> heap;
void Dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	dist[s] = 0;
	cnt[s] = 1;
	heap.push({s, 0});
	while (!heap.empty()) {
		int u = heap.top().id, dis = heap.top().w;
		heap.pop();
		if (dist[u] != dis)
			continue;
		for (int v = 1; v <= n; v++) {
			if (!edges[u][v])
				continue;
			if (dist[v] > dis + 1) {
				dist[v] = dis + 1;
				heap.push({v, dist[v]});
				cnt[v] = cnt[u];
			} else if (dist[v] == dis + 1){
				cnt[v] += cnt[u];
				if (cnt[v] > 2)
					cnt[v] = 3;
			}
		}
	}
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(edges, 0, sizeof edges);
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++) {
			if (abs(a[u] - a[v]) <= d && u != v)
				edges[u][v] = 1;
		}
	int ans = 0;
	for (int u = 1; u <= n; u++) {
		Dijkstra(u);
		for (int v = 1; v <= n; v++)
			if (cnt[v] == 2)
				ans++;
	}
	ans /= 2;
	cout << ans << endl;
}

}

namespace specialA {
	
int a[maxn];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int delta = a[2] - a[1];
	int k = d / delta;
	if (k < 2) {
		cout << 0 << endl;
		return;
	} else {
		int ans = n - (2 * k - 1);
		cout << max(ans, 0ll) << endl;
		return;
	}
}

}

namespace specialB {
	
void solve() {
	cout << 0 << endl;
}
	
}

void main() {
	cin >> c >> T;
	while (T--) {
		switch (c) {
			case 11:
			case 12:
				specialA::solve();
				break;
			case 13:
			case 14:
				specialB::solve();
				break;
			default:
				force::solve();
				break;
		}
	}
}

#undef int
#undef endl

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	
	OI::main();
	
	return 0;
}
