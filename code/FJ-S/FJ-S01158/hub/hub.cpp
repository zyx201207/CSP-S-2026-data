#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n , k , ans;
vector <int> g[1000005];
//int f[4005][4005][2][2];

//void dfs(int x , int fa){
//	for(int nxt : g[x]) if(nxt != fa){
//		dfs(nxt , x);
//		for(int i = 1;i <= k;i++){
//			f[x][i][0][0] = min(f[x][i][0][0] , f[nxt][i][0][0]);
//			f[x][i][0][1] = min(f[x][i][0][1] , f[nxt][i - 1][0][1]);
//		}
//	}
//}

bool qwq[1005];
int dis[1005]; bool vis[1005];
inline void bfs(){
	queue <int> q;
	for(int i = 1;i <= n;i++) dis[i] = 11451419;
	for(int i = 1;i <= n;i++) vis[i] = 0;
	for(int i = 1;i <= n;i++)
		if(qwq[i]){
			q.push(i);
			dis[i] = 0; vis[i] = 1;
		}
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(int nxt : g[t]){
			if(dis[nxt] > dis[t] + 1){
				dis[nxt] = dis[t] + 1;
				if(!vis[nxt]){
					vis[nxt] = 1;
					q.push(nxt);
				}
			}
		}
	}
}

bool ppp[105];
void ck(int x , int fa){
	if(!qwq[x]) return ;
	ppp[x] = 1;
	for(int nxt : g[x]) if(nxt != fa)
		ck(nxt , x);
}

inline int lcj(){
	int ret = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++) ppp[i] = 0;
	for(int i = 1;i <= n;i++) if(qwq[i] && !ppp[i]){
		if(cnt == 2) return 11451419;
		cnt++;
		ck(i , 0);
	}
	bfs();
	for(int i = 1;i <= n;i++) ret = max(ret , dis[i]);
	return ret;
}

void dfs(int x , int y){
	if(y == 0){
		ans = min(ans , lcj());
		return ;
	}
	if(x > n) return ;
	qwq[x] = 1;
	dfs(x + 1 , y - 1);
	qwq[x] = 0;
	dfs(x + 1 , y);
}

int main(void){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
//	freopen("hub3.in" , "r" , stdin);
	int c , T; scanf("%d%d" , &c , &T);
	while(T--){
		scanf("%d%d" , &n , &k);
		for(int i = 1;i <= n;i++) g[i].clear();
		for(int i = 1 , u , v;i < n;i++){
			scanf("%d%d" , &u , &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = 114514191;
		dfs(1 , k);
		printf("%d\n" , ans);
	}	
	return 0;
}
