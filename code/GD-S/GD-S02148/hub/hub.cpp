#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;//15 ·Ö´úÂë 
int ppcnt(int x){
	int res = 0;
	while(x){
		x&=(x-1);
		res++;
	}
	return res;
}
int n, k;
bool vis[N], bz[N];
int dis[N];
vector<int> g[N];
void dfs1(int x){
	bz[x] = false;
	for(int v : g[x]){
		if(bz[v])dfs1(v);
	}
}
bool check(){
	int cnt = 0;
	for(int i = 1; i <= n; i ++){
		if(bz[i]){
			cnt++;
			dfs1(i);
		}
	}
	return (cnt==2);
}
int mxdp, mx;
void dfs(int x,int fa){
	dep[x] = dep[fa] + 1;
	if(dep[x]>dep[mx])mx = x, mxdp = dep[x];
	for(int v : g[x]){
		if(v==fa)continue;
		dfs(v,x);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		g[i].clear();
	}
	for(int i = 1, u = 0, v = 0; i < n; i ++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n<=10){
		int ans = 1e9;
		int all = (1<<n)-1;
		for(int i = 1; i <= all; i ++){
			if(ppcnt(i)!=k)continue;
			for(int j = 1; j <= n; j ++){
				if((1<<(j-1))&i){
					vis[j] = true;
					bz[j] = true;
				}
				else{
					vis[j] = false;
					bz[j] = false;
				}
			}
			if(check()){
				int ths = 0;
				for(int j = 1; j <= n; j ++){
					if(!vis[j]){
						for(int k = 1; k <= n; k ++){
							dis[k] = -1;
						}
						dis[j] = 0;
						queue<int> q;
						while(!q.empty())q.pop();
						q.push(j);
						bool flag = 0;
						while(!q.empty()){
							int x = q.front();q.pop();
							for(int v : g[x]){
								if(dis[v]==-1){
									dis[v] = dis[x] + 1;
									if(vis[v]){
										ths = max(ths, dis[v]);
										flag = 1;
										break;
									}
									else{
										q.push(v);
									}
								}
							}
							if(flag)break;
						}
					}
				}
				ans = min(ans, ths);
			}
		}
		cout << ans << endl;
	}
	else if(k>=n-3){
		puts("0");return;
	}
	else{
		mx = mxdp = 0;
		dfs(1,0);
		k/=2;
		cout << (mxdp+2)/3-k/2 << endl;
	}
}
int ca, T;
signed main (){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> ca >> T;
	while(T--){
		solve();
	}
}
