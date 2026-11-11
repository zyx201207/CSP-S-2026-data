#include <bits/stdc++.h>
#define _for(i,a,b) for(int i = a,IM = b;i <= IM;i ++)
using namespace std;
const int N = 5000 + 9;
using ll = long long;
const ll inf = 1e16 + 9;
ll pos[N];
ll dist[N][N]; 
int cnt[N][N]; // 最短路计数 
int ans = 0;
int n; 
void dfs(int s,int now,int cur = 0){
	for(int v = now + 1;v <= n;v ++){
		int d = cur + 1;
		if(d == dist[s][v])cnt[s][v] ++;
		dfs(s,v,d);
	} 
}
void solve(){
	ll d; cin >> n >> d;
	_for(i,1,n) cin >> pos[i];
	_for(l,1,n) {
		_for(r,l + 1,n){
			dist[l][r] = inf;  
			if(pos[r] - pos[l] + 1 <= d)dist[l][r] = 1;
		}
	}
	_for(k,1,n){
		_for(l,1,k - 1){
			_for(r,k + 1,n) {
				dist[l][r] = min(dist[l][r],dist[l][k] + dist[k][r]);
			} 
		} 
	}
	_for(i,1,n) dfs(i,i);
	ans = 0;
	_for(l,1,n) _for(r,l + 1,n) ans += cnt[l][r] == 2;
	cout << ans << '\n';
	_for(l,1,n)_for(r,1,n) cnt[l][r] = 0;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t; cin >> c >> t;
	while(t --) solve(); 
	return 0;
} 
