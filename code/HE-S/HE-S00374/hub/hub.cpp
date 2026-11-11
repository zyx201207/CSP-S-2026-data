#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e6 + 5;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			int u, v;
			cin >> u >> v;
		}
		cout<<(n/2-k)/4+2<<'\n';
	} 
	return 0;
}
