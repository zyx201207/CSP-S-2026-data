// 0 pts
#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5, N = 505;
int c, n, m, d, q, w[M], no[M], tot, h[M], dist[N], tr[M][N];
struct edge{ int to, next, line; } e[M << 1];
void add(int u, int v, int line){
	e[++tot] = {v, h[u], line};
	h[u] = tot;
}
struct node{ int dist, no, crt_line; };
struct a{ bool operator()(node a, node b){ return a.dist > b.dist; } };
priority_queue<node, vector<node>, a> pq;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
			cin >> no[j] >> tr[no[j]][i];
		for(int j = 2;j <= k;j++){
			add(no[j], no[j - 1], i);
			add(no[j - 1], no[j], i);
		}
	}
	for(int i = 1;i <= q;i++){
		int start, end;
		cin >> start >> end;
		memset(dist, 0x3f, sizeof dist);
		pq.push({0, start, 0});
		dist[start] = 0;
		while(pq.size()){
			node t = pq.top();
			pq.pop();
			for(int j = h[t.no];j;j = e[j].next){
				int duv = t.dist;
				if(e[j].line != t.crt_line) duv += tr[t.no][t.crt_line] + tr[e[j].to][e[j].line];
				if(dist[e[j].to] > duv){
					dist[e[j].to] = duv;
					pq.push({duv, e[j].to, t.crt_line});
				}
			}
		}
		cout << dist[end] + w[start] + w[end] << endl;
	}
	return 0;
}
