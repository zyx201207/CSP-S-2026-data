#include <bits/stdc++.h>
using namespace std;
vector <int> g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1;i <= n;i++) g[i].clear();
		for(int i = 1;i < n;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int m = n/2+1;
		if(k%2 == 0) k--;
		cout << m-(k/2+1) << "\n";
	}
	
	
	return 0;
}
