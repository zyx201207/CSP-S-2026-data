#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int N = 1e5 + 5;

int n;
int k;
int ans;
int mx;
bool vis[N];
bool m[3][N];
vector<int> g[N];


void ck(int u, int p){
	if(m[1][u] || m[2][u]){
		mx = max(mx, p);
	}
	rep(i,0,g[u].size() - 1,1){
		int v = g[u][i];
		if(v == u) continue;
		ck(v, p + 1);
	}
}

void f(int u, int b, int s){
	if(b > k || s > 2) return;
	if(b == k){
		mx = -INF;
		rep(i,1,n,1){
			if(m[1][i] || m[2][i]) continue;
			ck(i,0);
			ans = min(ans, mx);
		}
		return;	
	}
	
	rep(i,0,g[u].size()-1,1){
		int v = g[u][i];
		if(vis[v]) continue;
		if(m[1][u]) {
			m[1][v] = 1;
			f(v, b + 1, s);
			m[1][v] = 0;
		}
		else if(m[2][u]) {
			m[2][v]=1;
			f(v, b + 1, s);
			m[2][v] = 0;
		}
		else{
			f(v,b,s);
			f(v,b + 1, s + 1);
		}
	}
	
	return;	
}


int solve(){
	cin >> n >> k;
	ans = INF;
	rep(i,1,n - 1,1){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	rep(i,1,n,1){
		memset(vis,false,sizeof(vis));
		memset(m,false,sizeof(m));
		m[1][i] = 1;
		f(i,1,1);
	}
	
	cout << ans << endl;
	return 0;
}

int main(){

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);


	int c;
	int T;
	cin >> c >> T;
	while(T--){
		solve();
	} 



	return 0;
}








