#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int inf = 1e9 + 10;
const int N = 5e5 + 10;
const int M = 1e5 + 10;
int n, m, c, d, q;
vector<pair<int, int> > g[N];
int w1[N], t[505][505], a[505][505], k[505], dis[N], flag[N], anss[M];

struct qus {
	int frm, to, num, ans;
}ques[M];

bool cmp (qus x, qus y) {
	return x.frm < y.frm;
}

bool cmp2 (qus x, qus y) {
	return x.num < y.num;
}

struct node {
	int pos, val;
	friend bool operator < (node x, node y) {
		return x.val > y.val;
	}
};

priority_queue<node> qq;

void dijk (int st, int ed) {
	vector<int> vis(m + 5);
	for (int i = 1;i <= m;i ++) dis[i] = inf;
	dis[st] = 0;
	qq.push({st, 0});
	while (!qq.empty()) {
		node tmp = qq.top();
		qq.pop();
		int u = tmp.pos;
		if (vis[u]) continue;
		vis[u] = 1;
		for (pair<int, int> tp : g[u]) {
			int v = tp.first;
			int w = tp.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				qq.push({v, dis[v]});
			}
		}
	}
}

signed main () {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++) {
		cin >> w1[i];
	}
	for (int i = 1;i <= n;i ++) {
		cin >> k[i];
		for (int j = 1;j <= k[i];j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	//int ttt = clock();
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= k[i];j ++) {
			int u = a[i][j];
			for (int kk = j + 1;kk <= k[i];kk ++) {
				int v = a[i][kk];
				int w = t[i][j] + t[i][kk];
				g[u].push_back({v, w});
				g[v].push_back({u, w});
			}
		}
	}
	for (int i = 1;i <= q;i ++) {
		cin >> ques[i].frm >> ques[i].to;
		ques[i].num = i;
	}
	sort (ques + 1, ques + q + 1, cmp);
	for (int i = 1;i <= q;i ++) {
		int st = ques[i].frm, ed = ques[i].to;
		if (!flag[st]) {
			dijk(st, ed);
			flag[st] = 1;
		} 
		ques[i].ans = dis[ed] + w1[st] + w1[ed];
		anss[ques[i].num] = ques[i].ans;
	}
	for (int i = 1;i <= q;i ++) {
		cout << anss[i] << endl;
	}
	//int tttt = clock();
	//cout << tttt - ttt << "ms" << endl;
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
