#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int to, next;
}ma[2000007];
int head[1000007], tot;
int d[500007], sz[500007];
int top[500007], son[500007];
int fa[500007], c, t, n, k, vis[500007];
void add(int x, int y){
	ma[++tot].to = y;
	ma[tot].next = head[x];
	head[x] = tot;
}
void dfs(int u){
	d[u] = d[fa[u]] + 1;
	sz[u] = 1;
	for(int i = head[u];i;i = ma[i].next){
		int v = ma[i].to;
		if(v == fa[u]){
			continue;
		}
		fa[v] = u;
		dfs(v);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]){
			son[u] = v;
		}
	}
}
void dfs(int u, int f){
	top[u] = f;
	if(!son[u]){
		return;
	}
	dfs(son[u], f);
	for(int i = head[u];i;i = ma[i].next){
		int v = ma[i].to;
		if(v == fa[u] || v == son[u]){
			continue;
		}
		dfs(v, v);
	}
}
int LCA(int x, int y){
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]){
			swap(x, y);
		}
		x = fa[top[x]];
	}
	if(d[x] > d[y]){
		swap(x, y);
	}
	return x;
}
void bfs(int s){
	queue<int> q;
	int vis[5007] = {};
	vis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];i;i = ma[i].next){
			int v = ma[i].to;
			if(vis[v]){
				continue;
			}
			q.push(v);
			vis[v] = 1;
			if(::vis[v]){
				::vis[v] = 2;
			}
		}
	}
}
int check(){
	int tot = 0;
	for(int i = 1;i <= n;++i){
		if(vis[i] == 1){
			bfs(i);
			tot++;
		}
	}
	return tot <= 2;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int ans = 0x7fffffff;
		cin >> n >> k;
		for(int i = 1;i < n;++i){
			int u, v;
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		dfs(1);
		dfs(1, 1);
		for(int sta = 0;sta < (1 << n);++sta){
			int sum = 0;
			for(int i = 1;i <= n;++i){
				if(sta & (1 << (i - 1))){
					vis[i] = 1;
					sum++;
				}
			}
			if(sum != k){
				for(int i = 1;i <= n;++i){
					vis[i] = 0;
				}
				continue;
			}
			if(!check()){
				for(int i = 1;i <= n;++i){
					vis[i] = 0;
				}
				continue;
			}
			int tmp = 0;
			for(int i = 1;i <= n;++i){
				if(!vis[i]){
					continue;
				}
				for(int j = 1;j <= n;++j){
					if(vis[j]){
						continue;
					}
					tmp = max(tmp, d[i] + d[j] - d[LCA(i, j)]);
				}
			}
			ans = min(ans, tmp);
			for(int i = 1;i <= n;++i){
				vis[i] = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
