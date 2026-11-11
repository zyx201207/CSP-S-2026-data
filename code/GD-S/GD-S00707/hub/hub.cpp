#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[2000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		int n,k;
		cin >> n >> k;
		for (int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << (n-k)/2 << endl;
	}
	return 0;
}
