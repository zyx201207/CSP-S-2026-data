#include <bits/stdc++.h>
using namespace std;

struct Node {
	int s, step;
};

struct Edge {
	int a, v;
};

vector <int> a, t;
queue <Node> q;
vector <Edge> Edges[1005];
int n, m, d, c, b;
bool vis[505]; 	

void bfs (int x, int y) {
	memset (vis , false , sizeof (vis));
	while (!q.empty()) 
		q.pop();
	q.push({x, 0});
	while (!q.empty()) {
		Node f = q.front();
		if (f.s == y) {
			printf ("%d\n", f.step);
			return;
		}
		for (auto l : Edges[f.s]) 
			if (!vis[l.a]) 
				q.push({l.a, f.step + l.v}), vis[l.a] = true;
		q.pop();
	}
}

int main () {
	
	freopen ("subway.in" , "r" , stdin);
	freopen ("subway.out" , "w" , stdout);
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &b);
	for (int i = 1; i <= m; i ++) {
		int w;
		scanf ("%d", &w);
		Edges[i + m].push_back({i , w});
		Edges[i].push_back({i + m , w});
	}
	for (int i = 1; i <= n; i ++) {          
		int k;
		scanf ("%d", &k);
		while  (!a.empty())
			a.pop_back();
		while (!t.empty())
			t.pop_back();
		a.push_back(-1);
		t.push_back(-1);
		for (int i = 1; i <= k; i ++) {
			int aa, tt;
			scanf ("%d%d", &aa, &tt);
			a.push_back(aa);
			t.push_back(tt);
		}
		for (int j = 1; j <= k; j ++) 
			for (int p = 1; p <= k; p ++) 
				if (j != p) 
					Edges[a[j] + m].push_back({a[p] + m, t[j] + t[p]}) , Edges[a[p] + m].push_back({a[j] + m, t[j] + t[p]});
	}
	while (b --) {
		int x, y;
		scanf ("%d%d", &x, &y);
		bfs (x , y);
	}
	
	return 0;
}
