#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 500003
#define int long long
inline int read(){
	int xxxx = 0, ffff = 1;
	char cchh = getchar();
	while(cchh < 48 || cchh > 57) ffff = (cchh == 45 ? -1 : ffff), cchh = getchar();
	while(cchh >= 48 && cchh <= 57) xxxx = (xxxx << 1) + (xxxx << 3) + (cchh ^ 48), cchh = getchar();
	return xxxx * ffff;
}
int n, m, w[N], d[5003][5003], f[5003][5003];
std :: vector<int> g[N];
inline void dijkstar(int s){
	for(int i = 1; i <= n; ++i) d[s][i] = 1e9, f[s][i] = 0;
	d[s][s] = 0, f[s][s] = 1; std :: queue<std :: pair<int, int> > q;
	q.push({0, s});
	while(q.size()){
		int h = q.front().second, dis = q.front().first; q.pop();
		for(auto to : g[h]){
			if(d[s][to] > dis + 1) d[s][to] = dis + 1, f[s][to] = f[s][h], q.push({d[s][to], to});
			else if(d[s][to] == dis + 1 && f[s][to] <= 2) f[s][to] += f[s][h];
		}
	} 
} 
inline void solve(){
	n = read(), m = read();
	for(int i = 1; i <= n; ++i) w[i] = read(), g[i].clear(), g[n + i].clear();
	for(int i = 1; i <= n; ++i){
		int l = std :: lower_bound(w + 1, w + 1 + n, w[i] - m) - w, r = std :: upper_bound(w + 1, w + 1 + n, w[i] + m) - w - 1;
		for(int j = l; j <= r; ++j) g[j].emplace_back(i);
	}
	for(int i = 1; i <= n; ++i) dijkstar(i);
	int result = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			if(f[i][j] == 2) ++result;
		}
	}
	printf("%lld\n", result);
}
signed main(){
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	int id = read(), T = read();
	while(T--) solve();
	return 0;
}
/*
w_s + w_t + t_p_1, s_1 + t_p_1, t_1 + ....
 
*/
