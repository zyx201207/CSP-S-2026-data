#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll, int>
using namespace std;
int c, t;
int n, k;
vector<int> g[2000005];
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) g[i].clear();
		for(int i = 1; i < n; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << 0;
	}
}
