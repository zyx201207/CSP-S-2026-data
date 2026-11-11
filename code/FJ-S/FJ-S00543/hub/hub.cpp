
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k;
vector<int> g[N];


int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C, T;
	cin>> C >> T;
	while(T --) {//多测清空了，你气不气？ ‘_’ 
		cin >> n >> k;
		for(int i = 1; i <= n; i ++) {
			while(g[i].size()) g[i].pop_back();
		}
		for(int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool A = true;
		for(int i = 2; i < n; i ++) { //lian
			if(g[i].size() != 2) {
				A = false;
			}
		}
	
			int ans = 0;
			int kuai = n / k, lkuai = 1, hkuai = kuai;
			for(int i = 1; i <= n; i ++) {
				if(i % kuai != 0) {
					ans = max(ans, min(hkuai - i, i - lkuai));
				}
				else {
					lkuai = i, hkuai = i + kuai;
				}
			}
			cout << ans;
		
		//cout <<"";
	}
	return 0;
} 
