#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100010;
const int inf = 0x3f3f3f3f;

int c, n, m, d, q;
int w[N];
int a[100][510];
int t[100][510];
ll dis[N];




struct node{
	int v;
	ll d;
};
vector<node> edge[N];

int read(){
	int x = 0, flag = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * flag;
}

int getid(int line, int pos){
	return line * m + pos;
}

struct DIJ{
	int u;
	ll dist;
	bool operator <(const DIJ &other) const{
		return dist > other.dist;
	}
};

void dij(int s){
	priority_queue <DIJ> pq;
	memset(dis, inf, sizeof(dis));
	dis[s] = 0;
	pq.push({getid(0, s), dis[s]});
	while(!pq.empty()){
		DIJ cur = pq.top(); pq.pop();
		int u = cur.u;
		if(cur.dist > dis[u]) continue ;
		for(auto nxt : edge[u]){
			int v = nxt.v;
			ll w = nxt.d;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push({v, dis[v]});
			}
		}
	}
	return ;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
//	cin >> c >> n >> m >> d >> q;
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
//			cin >> a[i][j];
			a[i][j] = read();
			t[i][a[i][j]] = read();
//			cin >> t[i][a[i][j]];
			if(j == 1) continue ;
			edge[getid(i, a[i][j])].push_back({getid(i, a[i][j - 1]), 0});
			edge[getid(i, a[i][j - 1])].push_back({getid(i, a[i][j]), 0});
		}
	}
	
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			if(t[i][j]){
//				cout << i << " : " << j << endl;
				edge[getid(0, j)].push_back({getid(i, j), t[i][j]});
				edge[getid(i, j)].push_back({getid(0, j), t[i][j]});
			}
		}
	}
	
//	for(auto nxt : edge[2]){
//		int v = nxt.v;
//		int w = nxt.d;
//		cout << 2 << " -> " << v << " : " << w << endl;
//	}
	
//	cout << dis[getid(2, )]
	
	while(q--){
		int x = read();
		int y = read();
		
		dij(x);
		int ans = w[x] + w[y] + dis[y];
//		cout << w[x] << " " << w[y] << endl;
//		cout << dis[getid(1, 2)] << " " << dis[getid(0, 2)] << " " << dis[getid(2, 2)] << endl;
//		cout << dis[getid(1, 1)] << " " << dis[getid(1,2)] << " " << dis[getid(2, 2)] << " " << dis[getid(2, 3)] << " " << dis[getid(0, 3)] << endl;
//		cout << dis[2] << endl;
		cout << ans << '\n';
	}
	return 0;
}
