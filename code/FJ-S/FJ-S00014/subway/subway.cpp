#include <bits/stdc++.h>
using namespace std;

int const N = 2e4 + 10;

vector<long long> a[N];

long long t[510][N];

struct Node2{
	long long s, a;
};

vector<Node2> vt[N];

struct Node{
	long long s, k, a;
};

int tt[N];

long long bfs(int x, int y) {
	long long ans = 1e9 + 10;
	queue<Node> qe;
	qe.push({x, 0, 0});
	while(!qe.empty()) {
		Node p = qe.front(); qe.pop();
		if(p.s == y) ans = min(ans, (long long)p.k + tt[x] + tt[y] + t[p.a][p.s]);
		else{
			for(auto i : vt[p.s]) {
				if(p.a != i.a) qe.push({i.s, (long long)p.k + t[p.a][p.s] + t[i.a][p.s], i.a});
				else qe.push({i.s, p.k, p.a});
			}
		}
	}
	return ans;
}

int main()
{
	freopen("subway.in", "r", stdin);      
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> tt[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			long long ai, ti;
			cin >> ai >> ti;
			a[i].push_back(ai); t[i][ai] = ti;
		}
		for(int j = 0; j < k - 1; j++)  vt[a[i][j]].push_back({a[i][j + 1], i});
	}
	for(int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << bfs(x, y) << endl;
	}
	return 0;
}
