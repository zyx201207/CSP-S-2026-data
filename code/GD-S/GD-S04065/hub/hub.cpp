#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++)
using namespace std;
const int N = 5e5 + 9,inf = 1e9 + 9;

vector<int> ve[N];

int calc(int k) {
	int cnt = 0;
	while(k) k &= k - 1,cnt ++;
	return cnt; 
} 
int fa[N];
bool usd[N],rt[N];
int finding(int x){
	if(x != fa[x]) fa[x] = finding(fa[x]);
	return fa[x]; 
}
bool vis[N];
int dist[N];
void solve(){
	int n,k; cin >> n >> k;
	_for(i,1,n - 1) {
		int u,v; cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u); 
	}
	int mn = inf;
	_for(mask,1,(1 << n) - 1){
//		int mask = (1 << 3) + (1 << 0); 
		if(calc(mask) != k)continue;
		_for(i,1,n) fa[i] = i,usd[i] = false,rt[i] = false;
		vector<int>p;
		_for(i,1,n)if(mask >> i - 1 & 1)p.push_back(i),usd[i] = true;
		for(int u : p){
			for(int v : ve[u]) {
				if(usd[v] == false) continue;
				int da = finding(u),db = finding(v);
				if(da == db) continue;
				fa[da] = db;
			}
		}
		int cnt = 0;
		_for(i,1,n) if(usd[i]) rt[finding(i)] = true;
		_for(i,1,n) cnt += rt[i];
		if(cnt > 2) continue;
		queue<int>qu;
		_for(i,1,n) dist[i] = inf;
//		cout << "pp\n";
		for(int x : p) qu.push(x),dist[x] = 0; // ,cout << x << ' '; cout << '\n';
		 
		while(!qu.empty()) {
			int u = qu.front();qu.pop();
			for(int v : ve[u]) if(dist[v] == inf) {
				dist[v] = dist[u] + 1;
				qu.push(v);
			} 
		}
		int mx = 0;
		_for(i,1,n) mx = max(mx,dist[i]);
		mn = min(mn,mx);
	}
	cout << mn << '\n';
	_for(i,1,n)ve[i].clear(),vis[i] = false;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t; cin >> c >> t;
	while(t --)solve(); 
	return 0;
} 
