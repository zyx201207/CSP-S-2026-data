#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, a[5005], dis[5005], ans, cnt[5005];
vector<int> e[5005];
queue<int> q;
void dj(int x){
	while(!q.empty())q.pop();
	memset(dis, 0x7f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	q.push(x);
	dis[x] = 0;
	cnt[x] = 1;
	while(!q.empty()){
		int u = q.front();
//		printf("%lld %lld\n", u, dis[u]);
		q.pop();
		for(auto v : e[u]){
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(v);
				cnt[v] = cnt[u];
			}
			else if(dis[u] + 1 == dis[v])cnt[v] += cnt[u];
		}
	}
	for(int i = 1; i <= n; i++){
		if(cnt[i] == 2)ans++;
//		printf("%lld %lld %lld %lld\n", x, i, dis[i], cnt[i]);
	}
//	puts("");
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &d);
		ans = 0;
		for(int i = 1; i <= n; i++)e[i].clear();
		for(int i = 1; i <= n; i++){
			scanf("%lld", a + i);
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(a[j] - a[i] <= d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
//		for(int i = 1; i <= n; i++){
//			printf("%lld : ", i);
//			for(auto j : e[i]){
//				printf("%lld ", j);
//			}
//			puts("");
//		}
		for(int i = 1; i <= n; i++){
			dj(i);
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}
