#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;

int c,T,n,k;
int head[N],nxt[N],to[N],tot = 0;
void add(int u,int v){
	to[++tot] = v,nxt[tot] = head[u],head[u] = tot;
}
bool a[N],vis[N];

void dfs(int u,int fa){
	vis[u] = 1;
	for(int i = head[u]; i; i = nxt[i]){
		int j = to[i];
		if(j == fa) continue;
		if(a[j]) dfs(j,u);
	}
}
bool check(){
	memset(vis,0,sizeof vis);
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] && !vis[i]){
			dfs(i,0);
			res++;
			if(res > 2) return 0;
		}
	}
	return 1;
}
bool f = 0;
ll res = 0;
ll bfs(int u){
	memset(vis,0,sizeof vis);
	queue <pair<ll,ll> > q;
	q.push({0,u});
	vis[u] = 1;
	while(q.size()){
		pair <ll,ll> t = q.front();
		q.pop();
		if(a[t.second]) return t.first;
		for(int i = head[t.second]; i; i = nxt[i]){
			int j = to[i];
			if(!vis[j]){
				vis[j] = 1;
				q.push({t.first + 1,j});
			}
		}
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			int u,v;
			cin >> u >> v;
			add(u,v),add(v,u);
		}
		ll ans = 1e9;
		for(int i = 0; i < (1 << n); i++){
			int cnt = 0;
			for(int j = 0; j < n; j++) a[j + 1] = (i >> j) & 1,cnt += (i >> j) & 1;
			if(cnt != k) continue;
			if(check()){
				res = 0;
				for(int i = 1; i <= n; i++){
					res = max(res,bfs(i));
				}
				ans = min(ans,res);
			}
		}
		cout << ans << endl;
		for(int i = 1; i <= n; i++) head[i] = 0;
		tot = 0;
	}
	return 0;
}
