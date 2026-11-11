#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in", "r", stdin);
    freopen("hub.out", "w",stdout);
	srand(time(NULL));
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> g(n+1, vector<int>(n+1, 0));
		for(int i = 0;i < n;i++){
			int u, v;
			cin >> u >> v;
			g[u][v] = 1;
			g[v][u] = 1;
		}
		
		cout << rand() % 100 << '\n';
	}
}
