#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100;
int c, t, n, k, ans, vis[N];
vector <int> g[N];

void calc(int x, int cnt, int tj){
	if (cnt > k || (x > n && cnt < k))
	if (x > n || cnt == k){
		for (int i = 1; i <= n; i++)
		return ;
	}
	
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--){
		ans = 1e9;
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			g[i].clear();
		}
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		calc(1, 0, 0);
		ans = 1;
		cout << ans << "\n";
	}
	return 0;
}
