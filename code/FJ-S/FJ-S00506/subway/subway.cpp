#include <bits/stdc++.h>
#define i64 long long 
using namespace std; 
bool beg; 
const int N = 505;  
const int M = 1005; 
int ID, n, m, d, k[N], a[N][M];   
i64 w[M], t[N][M], dsub[1005][N], dpos[1005][1005];  
struct node {
	int id; 
	i64 ti;  
};
vector<node> sub[M]; //第i个站的地铁集合 
struct Node {
	int op; 
	int id; 
};
bool fin; 
void bfs(int s) {
	queue<Node> q; 
	memset(dsub[s], 0x3f, sizeof(dsub[s])); 
	memset(dpos[s], 0x3f, sizeof(dpos[s])); 
	dpos[s][s] = 0; 
	for(int i = 0; i < sub[s].size(); i++) {
		int v = sub[s][i].id; 
		i64 w = sub[s][i].ti;  
		dsub[s][v] = w; 
		q.push({0, v}); 
	}
	while(!q.empty()) {
		Node cur = q.front(); q.pop(); 
		int u = cur.id; 
		if(cur.op) {
			for(int i = 0; i < sub[u].size(); i++) {
				int v = sub[u][i].id; 
				i64 w = sub[u][i].ti; 
				if(dsub[s][v] > dpos[s][u] + w) {
					dsub[s][v] = dpos[s][u] + w; 
					q.push({0, v});  
				}
			}
		} else { 
			for(int i = 1; i <= k[u]; i++) {
				int v = a[u][i]; 
				i64 w = t[u][i]; 
				if(dpos[s][v] > dsub[s][u] + w) {
					dpos[s][v] = dsub[s][u] + w; 
					q.push({1, v}); 
				}
			}
		}
	}
	return; 
} 
int main() { 
	//cerr << (&beg - &fin) / 1024. / 1024 << "MB\n"; 
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout); 
	int q; 
	scanf("%d %d %d %d %d", &ID, &n, &m, &d, &q); 
	for(int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]); 
	} 
	for(int i = 1; i <= n; i++) {
		scanf("%d", &k[i]); 
		for(int j = 1; j <= k[i]; j++) {
			scanf("%d %lld", &a[i][j], &t[i][j]); 
			sub[a[i][j]].push_back({i, t[i][j]}); 
		}      
	}  
	for(int i = 1; i <= m; i++) {
		bfs(i); 
//		for(int j = 1; j <= n; j++) {
//			cerr << i << ' ' << j << ":" << dpos[i][j] << endl; 
//		}
	} 
	for(int i = 1, u, v; i <= q; i++) {
		scanf("%d %d", &u, &v); 
//		cerr << dpos[u][v] << endl; 
		printf("%lld\n", w[u] + w[v] + dpos[u][v]); 
	}
	return 0; 
}
