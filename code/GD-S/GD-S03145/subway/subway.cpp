#include<bits/stdc++.h>
#define pii pair<int, ll>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 500005, M = 505;
int n, m, q, s, t;
ll w[N], dist[M][M];
vector<pii> e[M], p[N];
void dij(int start ,ll dis[]){
	priority_queue<pair<ll, int> > q;
	dis[start] = 0;
	q.push({0ll, start});
	while(!q.empty()){
		ll _dis = q.top().fi;
		int tar = q.top().se;
		q.pop();
		if(dis[tar] != _dis) continue;
		for(auto [to, val] : e[tar])
			for(auto [wy, tim] : p[to])
				if(dis[wy] > _dis + val + tim){
					dis[wy] = _dis + val + tim;
					q.push({dis[wy], wy});
				}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dist, 0x3f, sizeof dist);
	scanf("%d%d%d%d%d" ,&m ,&m ,&n ,&q ,&q);
	for(int i = 1;i <= n;i++)
		scanf("%lld" ,&w[i]);
	for(int i = 1, cnt;i <= m;i++){
		scanf("%d" ,&cnt);
		for(int j = 1, pos, time;j <= cnt;j++){
			scanf("%d%d" ,&pos ,&time);
			e[i].push_back({pos, time});
			p[pos].push_back({i, time});
		}
	}
	for(int i = 1;i <= m;i++) dij(i, dist[i]);
	while(q--){
		scanf("%d%d" ,&s ,&t);
		ll ans = 1e18;
		for(auto [wys, vls] : p[s])
			for(auto [wyt, vlt] : p[t])
				ans = min(ans, dist[wys][wyt] + vls + vlt);
		printf("%lld\n" ,ans + w[s] + w[t]);
	}
	return 0;
}
