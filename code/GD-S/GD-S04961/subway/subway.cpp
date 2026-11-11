#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

struct node{
	int next;
	int to;
	int w;	
}edge[N];

int head[N], cnt = 0;
int test_num, n, m, d, q, r, w_[N];
int k[505], W[N], a[N], t[N], x, y, s = 0;
pair<int, int> st[505];

void addedge(int u, int v, int w) {
	cnt++;
	edge[cnt].next = head[u];
	edge[cnt].to = v;
	edge[cnt].w = w;
	head[u] = cnt;
}

bool sp_A = 1;
int minn = INT_MAX;
int stage[N];

//graph? how to bulid it

void dfs(int now, int sum) {
	if (sum >= minn) return;
	if (now == y) {
		sum += t[now];
		minn = min(minn, sum);
		return;
	} 
	if (now > y) return;
	for (int i = 1; i <= n; ++i) {
		if (st[i].first == now) {
			dfs(st[i].second, sum + t[st[i].first]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> test_num >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) 
		cin >> w_[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		if (k[i] > 2) sp_A = 0;
		for (int j = 1; j <= k[i]; ++j) {
			cin >> a[j];
			cin >> t[a[j]];
			if (j != 1) 
				st[i].first = a[j - 1], st[i].second = a[j];
		}
	}
	while (q--) {
		cin >> x >> y;
		if (sp_A) {
			int s = 0;
			dfs(x, w_[x] + w_[y]);
			cout << minn << endl;
			minn = INT_MAX;
		} else cout << 0 << endl;
	}
	return 0;
} 
