#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXN = 505;
const ll MAXM = 5e5 + 7;
int c, n, m, d, q;
int kt[MAXM], L, a, t, x, y, x1 = -1;
int dist[MAXM + MAXN], done[MAXM + MAXN];
int P[MAXN][MAXN], K[MAXM];


struct node{
	int id;
	bool const operator < (node a) const{
		if(dist[a.id] < dist[id]) return 1;
		else return 0;
	}
}M[MAXM + MAXN];
struct edge{
	int w;
	int from, to;
	edge(int u, int v, int l){
		from = u;
		to = v;
		w = l;
	}
};

vector <edge> G[MAXM + MAXN];


void dijistra(int s){
	memset(done, 0, sizeof(done));
	priority_queue <node> q;
	q.push(M[s]);
	P[s][s] = 0;
	while(!q.empty()){
		node k = q.top();
		q.pop();
		done[k.id] = 1;
		for(int i = 0; i < G[k.id].size(); i++){
			node l;
			l.id = G[k.id][i].to;
			if(done[l.id] == 1){
				P[s][l.id] = min(P[s][l.id], G[k.id][i].w + P[s][k.id]);
			} else {
				q.push(M[l.id]);
				P[s][l.id] = G[k.id][i].w + P[s][k.id];
				cout <<endl << G[k.id].size() << endl <<  G[k.id][i].w << ' ' << P[s][k.id] << endl <<k.id <<' ' << l.id <<endl;
				done[i] = 1;
			}
		}
	}
}

int main(){
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;

	for(int i = 1; i <= m; i++) cin >> kt[i];
	for(int p = 1; p <= n; p++){
		cin >> L;
		for(int u = 1; u <= L; u++){
			cin >> a >> t;
			M[a].id = a;
			M[MAXM + p].id = MAXM+u;
			G[MAXM + p].push_back(edge(MAXM + p, a, t));
			G[a].push_back(edge(a, MAXM + p, t));
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		if(K[x] == 0){
			dijistra(x);
			cout << endl << endl;
			for(int a8 = 1; a8 <= m; a8++) cout << P[x][a8] << ' ' << x << ' ' << a8 << endl;
			K[x] = 1;
		}
		cout << P[x][y] + kt[x] + kt[y] << ' ';
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
