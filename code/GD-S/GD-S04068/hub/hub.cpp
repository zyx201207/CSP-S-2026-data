#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
void file() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
int n,k,dep[N],mid,dg[N],fnl;
bool vis[N],isp[N];
vector<int> g[N];
set<int> s;
int a[N];
void dfs(int u,int step) {
	dep[u] = step;
	vis[u] = true;
	for(auto v : g[u]) {
		if(!vis[v]) dfs(v,step+1);
	}
}
void dfs2(int u,int step) {
	if(step==mid) {
		bool flag = false;
		if(s.find(u)) flag = true;
		for(auto v : g[u]) {
			if(isp[v]) flag = true;
		}
		if(!flag) fnl++;
		s.insert(u);
		isp[u] = true;
	}
	vis[u] = true;
	for(auto v : g[u]) {
		if(!vis[v]) dfs2(v,step+1);
	}
}
bool check() {
	dfs(1,1);
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) vis[i] = false;
		if(dg[i]) dfs2(i,1);
	}
	if(fnl>2) return false;
	
}
void solve() {
	cin >> n >> k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) vis[i] = false;
	for(int i=1;i<=n;i++) isp[i] = false;
	for(int i=1;i<n;i++) {
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		dg[u]++;
		dg[v]++;
	}
	int l=1,r=n-2;
	while(l<=r) {
		mid = (l+r)/2;
		if(check()) r = mid-1;
		else        l = mid+1;
	}
}
int main() {
	// file();
	int fw,t=1;
	cin >> fw >> t;
	while(t--) solve();
}
