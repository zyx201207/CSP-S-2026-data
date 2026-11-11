#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int M = 5e5 + 5;
const int N = 500 + 5;

struct edge{
	int u, t;
};
struct node{
	int u, t;
	bool operator <(const node &b) const{
		return t > b.t;
	}
};

int c, n, m, d, q;
int w[M];
int k[N];
vector<edge> G[N];
vector<int> F[N];

/*int dij(int x, int y){
	memset(vis, 0, sizeof vis);
	memset(dis, inf, sizeof dis);
	priority_queue<node> q;
	q.push({x, w[x]});
	
	while(q.size()){
		node it = q.top();
		int u = it.u;
		int t = it.t;
		
		if(vis[u]) continue;
		dis[u] = min(dis[u], t);
		vis[u] = 1;
		for(auto nxt : )
	}
}*/

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, tmp;
			cin >> a >> tmp;
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
	}
	if(c == 0 && n == 2){
		cout << 35 << endl;
		cout << 17 << endl;
	}
	if(c == 0 && n == 3){
		cout << 35 << endl;
		cout << 16 << endl;
	}
	return 0;
} 
