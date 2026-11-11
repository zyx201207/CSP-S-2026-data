

#include <bits/stdc++.h>

using namespace std;

int c,n,m,d,q;
long long a[500009];
struct node {
	int to;
	long long tim;
};
int S = 0;
long long check[5009][5009];
vector<node> mp[600009];
long long dis[600009];

long long bfs (int s, int e) {
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		S = mp[x].size();
		for (int i = 0; i < S; i++) {
			if (dis[mp[x][i].to]<=dis[x]+mp[x][i].tim) {
				continue;
			}
			
			dis[mp[x][i].to] = dis[x]+mp[x][i].tim;

			q.push(mp[x][i].to);
		}
	}
	return dis[e];
}

void init () {
	for (int i = 0; i <= 550000; i++) {
		dis[i] = 1e15;
	}
}

int main () {
	
	freopen("subway.in", "r",stdin);
	freopen("subway.out", "w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			node p;
			cin >> p.to >> p.tim;
			mp[m+i].push_back(p);
			int y = p.to;
			p.to = m+i;
			mp[y].push_back(p);
		}
	}
	for (int i = 1; i <= q; i++) {
		int x,y;
		cin >> x >> y;
		init();
		cout << a[x]+a[y]+bfs(x,y) << endl;
	}
	
	return 0;
}
