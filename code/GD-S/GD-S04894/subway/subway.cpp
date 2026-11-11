#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 507;
const int M = 1e6 + 7;

int c, n, m, d, q, w[M];

int h[M], nxt[M], to[M], val[M], cnt;
void add(int a, int b, int c){
	to[++cnt] = b;
	val[cnt] = c;
	nxt[cnt] = h[a];
	h[a] = cnt;
}

struct node{
	int v, w;
	friend bool operator < (node a, node b){
		return a.w > b.w;
	}
} tmp;

int dis[N][N]; // d[i][j] -> (线路i->j)|min

void dij(int s){
//	cout << "为什么不跑???" << endl;
	// 666机魂不悦我没招了 
	priority_queue<node> q;
	bool vis[M];int dis0[M];
	for (int i = 1; i <= m; i++) {
		dis0[i] = LLONG_MAX;
		vis[i] = 0;
	}
	dis0[s] = 0;
	tmp.v = s;tmp.w = 0;q.push(tmp);
	while (!q.empty()){
		int u = q.top().v;q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = nxt[i]){
			int v = to[i];
			if (dis0[v] > dis0[u] + val[i]){
				dis0[v] = dis0[u] + val[i];
				tmp.v = v;tmp.w = dis[s][v];q.push(tmp);
			}
		}
	}
	for (int i = 1; i <= n; i++) dis[s][m + i] = dis0[m + i];
	return;
}


int get_d(int x, int y){
	int sum = LLONG_MAX;
	for (int i = h[x]; i; i = nxt[i])
		for (int j = h[y]; j; j = nxt[j])
			sum = min(sum, val[i] + val[j] + dis[to[i]][to[j]]);
		
	return sum + w[x] + w[y];
}
 
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	for (int i = 1; i <= n; i++){
		int op, x, y;
		cin >> op;
		while(op--){
			cin >> x >> y; 
			add(x, i + m, y);
			add(i + m, x, y);
//			cout << "add" << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
//		cout << "不是都跑到这里来了你不跑dij啊";
		dij(i + m);
	}
	for (int i = m + 1; i <= m + n; i++){
		for (int j = m + 1; j <= m + n; j++) cout << dis[i][j] << ' ';
		cout << "\n";
	}
		
		
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << get_d(x, y) << '\n';
	}
}
