#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0, c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x;
}
void print(long long x){
	if(x > 9) print(x / 10);
	putchar((x % 10) ^ 48);
}
const int N = 505, M = 500005, D = 22;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m, d, q;
int in_time[M];
long long dis[N][N];
int cnt[M];
pair<int, int> son[M][D];
inline void MIN(long long &x, long long y){
	x > y && (x = y);
}
inline void solve(){
	n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) in_time[i] = read();
	for(int i = 1; i <= n; i++){
		int k = read();
		for(int j = 1; j <= k; j++){
			int u = read(), w = read();
			son[u][++cnt[u]] = {i, w};
		}
	}
	for(int i = 1; i <= m; i++) sort(son[i] + 1, son[i] + 1 + cnt[i]);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			dis[i][j] = inf;
	for(int u = 1; u <= m; u++)
		for(int i = 1; i <= cnt[u]; i++)
			for(int j = i + 1; j <= cnt[u]; j++)
				MIN(dis[son[u][i].first][son[u][j].first], son[u][i].second + son[u][j].second);
	for(int k = 1; k <= n; k++)
		for(int u = 1; u <= k; u++)
			for(int v = k; v <= n; v++)
				MIN(dis[u][v], dis[u][k] + dis[k][v]);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			dis[j][i] = dis[i][j];
	for(int i = 1; i <= q; i++){
		int u = read(), v = read();
		long long ans = inf;
		for(int i = 1; i <= cnt[u]; i++)
			for(int j = 1; j <= cnt[v]; j++)
				MIN(ans, dis[son[u][i].first][son[v][j].first] + son[u][i].second + son[v][j].second);
		print(ans + in_time[u] + in_time[v]), putchar('\n');
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for(int test = read(), T = 1; T; T--) solve();
	return 0;
}
