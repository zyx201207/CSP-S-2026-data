#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define rand rnd
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 110, M = 500010;
struct edge{
	int v, nex;
}e[N << 1];
int n, k;
int head[N], cnt;
void add(int u, int v){
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
	e[++cnt] = {u, head[v]};
	head[v] = cnt;
}
int flag[N], dis[N]; 
void bfs(){
	queue<int> q;
	memset(dis, -1, sizeof dis);
	for(int i = 1; i <= n; i++){
		if(flag[i]) q.push(i), dis[i] = 0;
	}
	while(q.size()){
		int u = q.front();
		q.pop(); 
		for(int i = head[u]; i; i = e[i].nex){
			int v = e[i].v;
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}
int ans = 1e18;
void dfs(int pos, int len){
	if(len == k){
		bfs();
		int cmax = 0;
		for(int i = 1; i <= n; i++){
			cmax = max(dis[i], cmax);
		}
		ans = min(cmax, ans);
		return ;
	}
	if(pos > n) return ;
	flag[pos] = 1;
	dfs(pos + 1, len + 1);
	flag[pos] = 0;
	dfs(pos + 1, len);
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		memset(head, 0, sizeof head);
		cnt = 0, ans = 1e18;
		cin >> n >> k;
		for(int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			add(u, v);
		}
		dfs(1, 0);
		cout << ans << "\n";
	}
	
	return 0;
}
/*


*/
