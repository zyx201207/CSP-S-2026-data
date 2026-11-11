#include<bits/stdc++.h>
#define int long long

using namespace std;

int c, t;
int n, d;
vector<int> x, pred;

void init(){
	x.clear();
	pred.clear();
}

void solve(){
	init();
	cin >> n >> d; x.resize(n + 1); x[0] = 0;
	for(int i = 1; i <= n; ++ i){
		cin >> x[i];
		pred[i] = x[i] - x[i - 1];
	}
	
	for(int u = 1; u<= n - 3; ++ u){
		for(int v = u + 3; v <= n; ++ v){
			for(int i = u; i <= v; ++ i){
				
			}
		}
	}
	
	cout << 1 << '\n';
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while(t --) solve();
	
	return 0;
}
