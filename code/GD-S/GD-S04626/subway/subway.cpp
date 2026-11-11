#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v, w;
};
vector <node> ve[500001];
int c, n, m, d, q, w[500001], k, a[500001], t[500001], x, y, vis[501], sum[500001];
int ans;
void dfs(int st, int en, int now, int now1){
	if (st == en){
		ans = min(ans, now);
		return ;
	}
	for (int i = 0; i < ve[st].size(); i++){
		if (!vis[ve[st][i].v]){
			vis[ve[st][i].v] = 1;
			dfs(ve[st][i].v, en, now + ve[st][i].w, 1);
			vis[ve[st][i].v] = 0;
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++){
			scanf("%lld", &a[j]);
			scanf("%lld", &t[j]);
			sum[j] = sum[j - 1] + t[j];
		}
		for (int j = 1; j <= k; j++){
			for (int l = j + 1; l <= k; l++){
				ve[a[j]].push_back({a[l], t[l] + t[j]});
				ve[a[l]].push_back({a[j], t[l] + t[j]});
			}
		}
	}
	for (int i = 1; i <= q; i++){
		memset(vis, 0, sizeof(vis));
		scanf("%lld%lld", &x, &y);
		ans = LLONG_MAX;
		dfs(x, y, 0, 0);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
