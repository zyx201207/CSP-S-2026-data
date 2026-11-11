#include<bits/stdc++.h>
#define int long long
const int N = 5e3 + 10;
using namespace std;
int c, t, n, d, a[N], ans[N], all;
bool vis[N], flag;
vector<int> v[N];
void dfs(int e, int u, int num) {
	if(u == e) {
		flag = 1;
		ans[num]++;
		return ;
	}
	for(auto it : v[u]) {
		if(!vis[it]) {
			vis[it] = 1;
			dfs(e, it, num + 1);
			vis[it] = 0;
		}
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		all = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++) {
			v[i].clear();
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(abs(a[i] - a[j]) <= d) {
					v[i].push_back(j);
					v[j].push_back(i); 
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				memset(ans, 0, sizeof ans);
				memset(vis, 0, sizeof vis);
				flag = 0;
				dfs(j, i, 0);
				if(!flag) continue;
				for(int k = 1; ; k++) {
					if(ans[k]) {
						if(ans[k] == 2) all++;
						break;
					} 
				}
			}
		}
		cout << all << endl;
	}
	return 0;
}
/*
0 2 
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
