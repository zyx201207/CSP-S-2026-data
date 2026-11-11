#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

#define ll long long
#define N 1010
#define M 50010
#define Q 100010
typedef pair<int, int>PII;

int c, n, m, d, q;
int w[M];
int k[M];
int a[N][N], t[N][N];
ll dist[N][N];
bool st[N];
bool f[N];
queue<int>que;
vector<PII>g[N];
int maxx = -1;


struct stu{
	int c;
	int x, y;
}r[Q];

void dijkstra(int s){
	memset(st, false ,sizeof st);
	dist[s][s] = 0;
	priority_queue<PII, vector<PII>, greater<PII>>heap;
	heap.push({0, s});
	while(!heap.empty()){
		auto hp = heap.top();
		heap.pop();
		int v = hp.second;
		if(st[v])continue;
		st[v] = true;
		for(auto ne : g[v]){
			int u = ne.first;
			int w = ne.second;
			if(dist[s][u] > dist[s][v] + w){
				dist[s][u] = dist[s][v] + w;
				heap.push({dist[s][u], u});
			}
		}
	}
}

void spfa(int s){
	memset(st, false ,sizeof st);
	dist[s][s] = 0;
	st[s] = true;
	queue<int>hp;
	hp.push(s);
	while(!hp.empty()){
		int tp = hp.front();
		hp.pop();
		st[tp] = false;
		for(auto ne : g[tp]){
			int v = ne.first;
			int w = ne.second;
			if(dist[s][v] > dist[s][tp] + w){
				dist[s][v] = dist[s][tp] + w;
				if(!st[v]){
					hp.push(v);
					st[v] = true;
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1;i <= n; i++){
		cin >> w[i];
	}
	memset(dist, 0x7f, sizeof dist);
	for(int i = 1;i <= m; i++){
		cin >> k[i];
		maxx = max(maxx , k[i]);
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int s = y1 + y2;
		g[x1].push_back({x2, s});
		g[x2].push_back({x1, s});
	}
	for(int i = 1;i <= q; i++){
		cin >> r[i].x >> r[i].y;
		if(!f[r[i].x]){
			f[r[i].x] = true;
			que.push(r[i].x);
		}
	}
	while(!que.empty()){
		int tp = que.front();
		dijkstra(tp);
		que.pop();
	}
	for(int i = 1;i <= q; i++){
		cout << dist[r[i].x][r[i].y] + w[r[i].x] + w[r[i].y] << "\n";
	}

	return 0;
}

