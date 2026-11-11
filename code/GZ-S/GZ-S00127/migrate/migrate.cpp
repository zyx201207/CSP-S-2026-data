//GZ-S00127 ½ªÃú²Ó 
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 2e6 + 5;
const int INF = 0x3f3f3f3f;
LL C, T, n, d, x[MAXN], mx_r[MAXN], mx_l[MAXN];

int dis[MAXN];
LL dp[MAXN];
void bfs(int s){
	memset(dis, INF, sizeof(dis));
	dis[s] = 0;
	memset(dp, 0, sizeof(dp));
	dp[s] = 1;
	queue <int> que;
	que.push(s);
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int v = s + 1; v <= mx_r[u]; v++)
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, dp[v] = dp[u], que.push(v);
			else if(dis[v] == dis[u] + 1) dp[v] = dp[v] + dp[u];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i], mx_r[i] = 0;
		for(LL l = 1, r = 0; l <= n; l++){
			while(r + 1 <= n && x[r + 1] - x[l] <= d) r++;
			mx_r[l] = r;
		}
		if(C <= 10){
			LL ans = 0;
			for(int i = 1; i <= n; i++){
				bfs(i);
				for(int j = i + 1; j <= n; j++)
					ans += (dp[j] == 2);
			}
			cout << ans << "\n";
		}
		if(11 <= C && C <= 12){
			int len = mx_r[1] - 1;
			if(len >= 2) cout << max(0ll, n - 1 - 2 * len + 2) << "\n";
			else cout << "0\n";
		}
	}
	
	return 0;
} 
