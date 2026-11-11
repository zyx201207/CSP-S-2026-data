#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++)
#define _rep(i,a,b) for(int i = a,IM = b;i >= IM;i --)
using namespace std;
const int N = 5e5 + 9;
using ll = long long;
const ll inf = 1e18 + 9;
int w[N];
using pii = pair<int,int>;
vector<pii> ve[N];
ll dist[N];
int c,n,m,d,q; 
using pli = pair<ll,int>; 
void dij(int s){
	_for(i,1,m + n) dist[i] = inf;
	priority_queue<pli,vector<pli>,greater<pli> >pq;
	pq.push({dist[s] = 0,s});
	while(!pq.empty()){
		int u = pq.top().second; ll dis = pq.top().first;
		pq.pop();
		if(dist[u] != dis) continue;
		for(pii pi : ve[u]){
			int v = pi.first,w = pi.second;
			if(dist[v] > dist[u] + w)pq.push({dist[v] = dist[u] + w,v});
		}
	} 
}
int k[N];
bool check1(){
	int sum_k = 0; 
	_for(i,1,n) sum_k += k[i];
	return sum_k <= 405; 
}
void solve(){
	_for(i,1,q) {
		int l,r; cin >> l >> r;
		dij(l);
		cout << dist[r] + w[l] + w[r] << '\n';
	}
}
bool check2(){
	bool flag = true;
	_for(i,1,n) if(k[i] > 2)flag = false;
	return flag;
} 

int dep[N],f[N][20];

void dfs1(int u,int fa = 0){
	for(pii pi : ve[u]) if(pi.first != fa){
		int v = pi.first,w = pi.second;
		dist[v] = dist[u] + w;
		dfs1(v,u);
	}
	
}
void dfs2(int u,int fa = 0){
	f[u][0] = fa,dep[u] = dep[fa] + 1;
	_for(k,1,19) f[u][k] = f[f[u][k - 1]][k - 1];
	for(pii pi : ve[u]) {
		int v = pi.first;
		if(v == fa)continue;
		dfs2(v,u); 
	} 
} 
int lca(int a,int b){
	if(dep[a] < dep[b]) swap(a,b);
	_rep(k,19,0) if(dep[f[a][k]] >= dep[b]) a = f[a][k];
	if(a == b)return a;
	_rep(k,19,0) if(f[a][k] != f[b][k]) a= f[a][k] ,b = f[b][k];
	return f[a][0];
}
void solve1(){ // 此时是一棵树 
	dfs1(1);
	dfs2(1);
	_for(i,1,q) {
		int l,r; cin >> l >> r;
		
		cout << dist[l] + dist[r] - 2 * dist[lca(l,r)] + w[l] + w[r] << '\n';
	}
}
queue<int>qu;
void solve2(){	
	_for(i,1,q) {
		int l,r; cin >> l >> r;
		qu.empty();
		_for(i,1,m + n) dist[i] = 0;
		qu.push(l);
		while(!qu.empty()){
			int u = qu.front();qu.pop();
			for(pii pi : ve[u]) {
				int v = pi.first,w = pi.second;
				if(dist[v]) continue;
				dist[v] = dist[u] + w;
				qu.push(v); 
			}
		}
		cout << dist[r] + w[l] + w[r] << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin >> c >> n >> m >> d >> q;
	_for(i,1,m) cin >> w[i];
	int last = 0; // T == t
	bool T = true;
	_for(i,1,n) {
		cin >> k[i]; // 一条路线 
		_for(j,1,k[i]) {
			int x,t; cin >> x >> t;
			if(last == 0)last = t;
			else T &= last == t,last = t; 
			ve[x].push_back({i + m,t});
			ve[i + m].push_back({x,t});
		}
	}
	if(n <= 200 && q <= 200 && check1())solve();
	else if(check2())solve1();
	else if(T)solve2();
	return 0;
} 
