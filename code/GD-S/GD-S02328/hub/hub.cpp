#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+6;
const int M = 2e6+5;
int c, T, n, k;
vector<int> to[N];
void solve(){
	cin >> n >> k;
	for(int i = 1; i < N; i++) to[i].clear();
	for(int i = 1,u,v; i < n; i++){
		cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	cout << T << "\n";
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
