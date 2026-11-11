#include <iostream>
#include <vector>
#include <queue>
#define int long long
#define N 500003
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 1) + (xxxx << 3) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
}
int id, n, m, dr, q, w[N], d[5003][5003];
std :: vector<std :: pair<int, int> > g[N];
inline void dijkstar(int s){
	for(int i = 1; i <= n + m; ++i) d[s][i] = 1e18;
	d[s][s] = 0; std :: priority_queue<std :: pair<int, int>, std :: vector<std :: pair<int, int> >, std :: greater<std :: pair<int, int> > > q;
	q.push({0, s});
	while(q.size()){
		int h = q.top().second, dis = q.top().first; q.pop();
		if(dis != d[s][h]) continue;
		for(auto [to, w] : g[h]){
			if(d[s][to] > dis + w) d[s][to] = dis + w, q.push({d[s][to], to});
		}
	} 
} 
signed main(){
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	id = read(), n = read(), m = read(), dr = read(), q = read();
	for(int i = 1; i <= m; ++i) w[i] = read();
	for(int i = 1; i <= n; ++i){
		int k = read();
		while(k--){
			int u = read(), w = read(); g[u].emplace_back(m + i, w), g[m + i].emplace_back(u, w);
		}
	}for(int i = 1; i <= m; ++i) dijkstar(i);
	while(q--){
		int s = read(), t = read(); printf("%lld\n", w[s] + w[t] + d[s][t]);
	}
	return 0;
}
/*
w_s + w_t + t_p_1, s_1 + t_p_1, t_1 + ....
 
*/
