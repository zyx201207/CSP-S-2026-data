#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, c, t, a[N], ans, minn, f, dis, vis[N];
vector<int> v[N];
void dfs(int u, int fa, int mud, int s){
	if(u == mud){
		if(s == minn) f++;
		else minn = min(minn, s), f = 0;
		return;
	}
	if(vis[u]) return;
	vis[u] = 1;
	for(auto e : v[u]){
		if(e != fa) dfs(e, u, mud, s + 1);
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> dis;
		ans = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(abs(a[i] - a[j]) <= dis) v[i].push_back(j), v[j].push_back(i);
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				memset(vis, 0, sizeof vis);
				f = 0;
				minn = 0x3f;
				dfs(i, 0, j, 0);
				if(f == 1) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

