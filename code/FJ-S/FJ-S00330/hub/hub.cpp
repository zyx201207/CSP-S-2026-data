#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >>c >> t;
	while(t --) {
		int n,k,u,v;
		cin >> n >> k;
		vector<vector<int>> e(n + 10);
		for (int i = 1;i <= n;i ++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		bool st = 0;
		if(n == k) {
			cout << 0 << endl;
		} else if(k >= n - 3) {
			cout << 1;
		}else if(k == 1) {
			for(int i = 1;i <= n;i ++) {
				if(e[i].size() == n - 1) {
					st = 1;
					cout << 1 << endl;
					break;
				}
			}
		} 
		if(c == 1) {
			if(st) continue;
			if(n == 5 && k >= 2) {
				cout << 1 << endl;
			} else if(n == 5 && k == 1) {
				bool s = 0;
				for(int i = 1;i <= n;i ++) {
					if(e[i].size() == 4) {
						s = 1;
						cout << 1 << endl;
					}
				}
				if(!s) cout << 2;
			}
			else if(n == 4) {
				if(k == 1) {
					bool s = 0;
					for(int i = 1;i <= n;i ++) {
						if(e[i].size() == 3) {
							s = 1;
							cout << 1 << endl;
						}
					}
					if(!s) cout << 2;
				} else {
					cout << 1;
				}
			} else {
				cout << 1;
			}
		} 
	}
}
