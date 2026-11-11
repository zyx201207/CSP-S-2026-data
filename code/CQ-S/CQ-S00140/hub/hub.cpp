#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
const int N = 1e6 + 5;
vector <int> v[N];
int dep[N];
void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	for(int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if(y == fa) continue ;
		dfs(y, x);
	}
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) v[i].clear();
		for(int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1, 0);
		int mxid = 0;
		for(int i = 1; i <= n; i++) {
			if(dep[mxid] < dep[i]) {
				mxid = i;
			}
		}
		dfs(mxid, 0);
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			mx = max(mx, dep[i]);
		}
		cout << (mx - k) / 2 << '\n';
	}
	return 0;
}

