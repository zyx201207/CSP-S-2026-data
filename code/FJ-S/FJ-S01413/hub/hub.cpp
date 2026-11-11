#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 10;
int c, T;
int n, k;
int len[N][N];
vector<int> g[N];
vector<int> as;
int ans = LLONG_MAX;
void dfs(int i, int yi) {
	if (yi == 0) {
		int cnt = 0;
		for (int i : as) {
			for (int j : as) {
				if (len[i][j] > 1 && i != j) cnt++;
				if (cnt > 2) return;
			}
		}
		for (int i = 1; i <= n; i++) {
			int nans = 0;
			for (int j : as) {
				if (i != j) nans = max(nans,len[i][j]);
			}
//			cout<<";"<<nans<<endl;
			ans = min(ans,nans);
		}
		return;
	}
	if (i == n + 1) return;
	dfs(i + 1,yi);
	as.push_back(i);
	dfs(i + 1,yi - 1);
	as.pop_back();
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld", &c, &T);
	while(T--) {
		scanf("%lld%lld", &n, &k);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				len[i][j] = LLONG_MAX;
			}
		}
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%lld%lld", &u, &v);
			len[u][v] = 1;
			len[v][u] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (i != k && j != k && len[i][k] != LLONG_MAX && len[k][j] != LLONG_MAX && i != j)
						len[i][j] = min(len[i][j],len[i][k] + len[k][j]);
				}
			}
		}
		as.clear();
		ans = LLONG_MAX;
		dfs(1,k);
		printf("%lld\n", ans);
	}
	return 0;
}
