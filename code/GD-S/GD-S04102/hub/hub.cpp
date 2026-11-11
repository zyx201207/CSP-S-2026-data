#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 5;
int c,qwq,n,k,u[N],v[N],num[N],dep[N],d1[N],d2[N],d3[N],ans;
bool vis[N];
vector<int> g[N];
void dfs1(int x,int u,int fa){
	dep[u] = dep[fa] + 1;
	num[u] = 0,vis[u] = false;
	int mx = 0,cmx = 0;
	for(auto v : g[u]){
		if(v == fa)continue;
		dfs1(x,v,u);
		if(d1[v] > mx)cmx = mx,mx = d1[v];
		else if(d1[v] > cmx)cmx = d1[v];
		num[u] += num[v];
		vis[u] |= vis[v];
	}
	if(mx + cmx > x || !x){
		vis[u] = true;
	}
	if(vis[u])num[u]++;
	d1[u] = mx + 1;
}
void dfs2(int x,int u,int fa){
	if(!fa){
		ans = min(ans,num[u]);
		d2[u] = d3[u] = 0;
	}
	int mx = 0,cmx = 0,mx3 = 0;
	for(auto v : g[u]){
		if(v == fa)continue;
		if(d1[u] > mx)mx3 = cmx,cmx = mx,mx = d1[u];
		else if(d1[u] > cmx)mx3 = cmx,cmx = d1[u];
		else if(d1[u] > mx3)mx3 = d1[u];
	}
	for(auto v : g[u]){
		if(v == fa)continue;
		if(d1[v] == mx)d3[v] = cmx + mx3 + d2[u] - min({cmx,mx3,d2[u]}) + 1,d2[v] = max({cmx,d2[u]}) + 1;
		else d3[v] = cmx + mx + d2[u] - min({cmx,mx,d2[u]}) + 1,d2[v] = max({mx,d2[u]}) + 1;
		d3[v] = max(d3[v],d3[u]);
		if(d3[v] <= x)ans = min(ans,num[v]);
		dfs2(x,v,u);
	}
}
int calc(int x,int rt){
	ans = n + 1;
	dfs1(x,rt,0),dfs2(x,rt,0);
//	cout << x << " " << rt << " " << ans << endl;
	return ans;
}
bool chk(int x){
	for(int i = 1;i < n;i++){
		for(auto it = g[u[i]].begin();it != g[u[i]].end();){
			if(*it == v[i])it = g[u[i]].erase(it);
			else it++;
		}
		for(auto it = g[v[i]].begin();it != g[v[i]].end();){
			if(*it == u[i])it = g[v[i]].erase(it);
			else it++;
		}
		if(calc(x,u[i]) + calc(x,v[i]) <= k)return true;
		g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef LOCAL
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#endif
	cin >> c >> qwq;
	while(qwq--){
		cin >> n >> k;
		for(int i = 1;i <= n;i++)g[i].clear();
		for(int i = 1;i < n;i++){
			cin >> u[i] >> v[i];
			g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
		}
		int l = 0,r = n,ans = n;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(chk(mid))ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << endl;
	}
}
