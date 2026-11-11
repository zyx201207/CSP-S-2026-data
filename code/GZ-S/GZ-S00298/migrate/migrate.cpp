// GZ-S00298 游景智 
// 40pts小部分一下 
#include<bits/stdc++.h>
using namespace std;
int c, T, n;
typedef pair<int,int> PII;
const int N = 2e6 + 10;
int dis[N];
typedef long long ll;
ll d;
ll x[N];
vector<int> g[N];
int vis[N];
void bfs(int s){
	for(int i = 1; i <= n; i++)dis[i] = 0, vis[i] = 0;
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	dis[s] = 0;
	while(q.size() > 0){
		int t = q.front();
		q.pop();
//		puts("R");
		for(int j : g[t]){
			if(!vis[j]){
				dis[j] = dis[t] + 1;
				vis[j]++;
				q.push(j); // 第一个到达一定最短 
			}else if(dis[t] + 1 == dis[j]){
				q.push(j); // 注意 
				vis[j]++;
			}
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--){
		ll ans = 0;
		for(int i = 1; i <= n; i++)
			g[i].clear(); 
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
			for(int j = i - 1; j >= 1; j--){
				if(x[i] - x[j] > d)break;
				g[j].push_back(i);
			}
		}
		for(int i = 1; i <= n; i++){
			bfs(i);
//			for(int k = i; k <= n; k++){
//				printf("%d ", dis[k]);
//			}
			for(int j = i + 1; j <= n; j++){
				if(!vis[j])break;
				if(vis[j] == 2)
					ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
