#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500 + 5, M = 5e5 + 5, MM = 1e7 + 5;
int c, n, m, d, q, w[M], k[N], a[M], t[M], num;
struct node{
	int x, s;
};
bool v[MM];
vector<node> metro[MM];
ll dfs(int now, int y){
	if(now == y)return 0;
	int l = metro[now].size();
	ll sum = 1e18;
	for(int i = 0; i < l; i++){
		int nex = metro[now][i].x;
		if(v[nex])continue;
		ll s = metro[now][i].s;
		if(s > sum)continue;
		v[nex] = 1;
		sum = min(sum, s + dfs(nex, y));
		v[nex] = 0;
	}
	return sum;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	num = m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%d%d", &a[j], &t[j]);
			metro[++num].push_back({a[j], t[j]});
			metro[a[j]].push_back({num, t[j]});
		}
		for(int j = num - k[i] + 1; j <= num; j++){
			for(int g = j + 1; g <= num; g++){
				metro[j].push_back({g, 0});
				metro[g].push_back({j, 0});
			}
		}
	}
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x] = 1;
		ll ans = dfs(x, y);
		v[x] = 0;
		ans += w[x];
		ans += w[y];
		printf("%lld\n", ans);
	}
	return 0;
}

