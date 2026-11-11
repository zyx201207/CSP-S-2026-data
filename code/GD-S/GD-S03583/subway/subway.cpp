#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
inline ll read(){
	int f = 1;ll x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return f * x;
}
//注意到：每条线内的点距离为0，是一个整体，因此将每条线路的点缩成一个 
//把每个站按线路暴力拆开，同一个站可以为不同的线路间提供一条边 
//此时有d个点，m*d^2条边，考虑flyod求解两条线路间最短路即可,略微卡常
ll c, n, m, d, q, w[N];
vector<pair<ll, ll>> a[N];
ll dis[510][510];
int main(){//O(N^3) 100pts 1h20min
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof dis);
	for(ll i = 1;i <= m;++ i) w[i] = read();
	ll k, u, t;
	for(ll i = 1;i <= n;++ i){
		dis[i][i] = 0;
		k = read();
		for(ll j = 1;j <= k;++ j){
			u = read();t = read();
			a[u].push_back({i, t});
		}
	}
	for(u = 1;u <= m;++ u){
		for(ll i = 0;i < a[u].size();++ i){
			for(ll j = 0;j < a[u].size();++ j){
				dis[a[u][i].first][a[u][j].first] = min(dis[a[u][i].first][a[u][j].first], a[u][i].second + a[u][j].second);
			}
		}
	}
	for(ll k = 1;k <= n;++ k){
		for(ll i = 1;i <= n;++ i){
			for(ll j = 1;j <= n;++ j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	ll v;
	while(q --){
		scanf("%lld%lld", &u, &v);
		ll ans = LONG_LONG_MAX;
		for(ll i = 0;i < a[u].size();++ i){
			for(ll j = 0;j < a[v].size();++ j){
				ans = min(ans, w[u] + w[v] + a[u][i].second + a[v][j].second + dis[a[u][i].first][a[v][j].first]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
