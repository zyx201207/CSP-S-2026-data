#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
int c,t;int n,k;
vector<int>tree[105];
bool vis[105],visi[105];
int fa[105];int minn;
inline int query(int x){return (fa[x] == x ? x : fa[x] = query(fa[x]));}
inline void merg(int x,int y){fa[query(x)] = query(y);}
inline void dfs(int now,int dis){
	visi[now] = 1;
	if(vis[now]){minn = min(minn,dis);}
	for(auto v : tree[now]){
		if(!visi[v]){
			dfs(v,dis+1);
		}
	}
}
inline void work(){
	cin >> n >> k;int ans = 1e18;
	for(int i = 1;i <= n;i++){tree[i].clear();}
	for(int i = 1;i < n;i++){int u,v;cin >> u >> v;tree[u].push_back(v);tree[v].push_back(u);}
	for(int mask = 0;mask < (1 << n);mask++){
		if(__builtin_popcount(mask) == k){
			fill(vis,vis+n+1,0);
			for(int j = 0;j < n;j++){
				fa[j+1] = j+1;
				if(mask & (1 << j)){vis[j+1] = 1;}
			}
			for(int j = 1;j <= n;j++){
				if(vis[j]){
					for(auto v : tree[j]){
						if(vis[v]){merg(v,j);}
					}
				}
			}
			int cnt = 0;
			for(int j = 1;j <= n;j++){
				if(vis[j] && query(j) == j){cnt++;}
			}
			
			if(cnt <= 2){
				int maxn = 0;
				for(int j = 1;j <= n;j++){
					if(!vis[j]){
						fill(visi,visi+n+1,0);
						minn = 1e18;
						dfs(j,0);
						maxn = max(maxn,minn);
					}
				}
				ans = min(ans,maxn);
			}
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){work();}
	return 0;
}
