#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;
const int maxn = 1e6 + 10;
int n, d;
int A[maxn];
vector<int> G[maxn];
int dfs(int u, int t, int f, int no){
	if(u == no) return 0;
	if(u == t) return 1;
	for(auto v : G[u]){
		if(v == f) continue;
		if(dfs(v, t, u, no)) return 1;
	}
}
int check(int x, int y){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(dfs(x, y, 0, i)) ans++;
	}
	return ans >= 2;
}
void go(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(abs(A[i] - A[j]) <= d) G[i].pb(j), G[j].pb(i);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(check(i, j)) ans++;
		}
	}
	cout << ans << endl;
}
void mian(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> A[i];
	if(n <= 5000){
		go();
	}else{
		int o = A[2] - A[1], f = 1;
		for(int i = 3; i <= n; i++){
			if(A[i] - A[i - 1] != o) f = 0;
		}
		if(!f){cout << 0 << endl;return;}
		if(o * 3 <= d){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(i + 3 <= n) ans += (n - i + 1 - 3);
			}
			cout << ans << endl; 
		}
	}
}
}using namespace kimi;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	int c, Test = 1;
	cin >> c >> Test;
	while(Test--) mian();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


freopen("migrate1.in", "r", stdin);
freopen("migrate.in", "w", stdin);
freopen("migrate.out", "r", stdout);
qisiwole
catch you!!
*/
