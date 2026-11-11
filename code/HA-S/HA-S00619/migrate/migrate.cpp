#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e3 + 10;
ll a[N], c, t, n, d, ans;
vector <int> g[N];

struct aaa {
	ll minn, val;
}mk[N];

struct node {
	ll id, len;
};

void bfs (int x) {
	queue <node> q;
	q.push((node) {x, 0});
	while (!q.empty()) {
		node p = q.front();
		q.pop();
		if (mk[p.id].minn == 0 || mk[p.id].minn == p.len) {
			mk[p.id].minn = p.len;
			mk[p.id].val ++;
		}
		for (int i : g[p.id]) {
			q.push((node){i, p.len + 1});
		}
	}
}

int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				if (a[j] - a[i] <= d) g[j].push_back(i);
			}
		}
		for (int i = 1; i <= n; i ++) {
			bfs(i);
			for (int i = 1; i <= n; i ++) {
				if (mk[i].val == 2) ans ++;
			}
			for (int i = 1; i <= n; i ++) {
				mk[i] = (aaa){0, 0};
			}
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i ++) {
			a[i] = 0;
			g[i].clear();
			ans = 0;
		}
	}
	return 0;
}

