#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,inf=1e9;
ll c,T,n,k,dis[15][15],ans;
bool is[15],mk[15];
vector<int> g[N];
void dfs1(int rt,int u,int p) {
	for(int v:g[u]) {
		if(v==p) continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs1(rt,v,u);
	}
}
void dfs2(int u,int p) {
	mk[u]=1;
	for(int v:g[u]) {
		if(v==p||!is[v]) continue;
		dfs2(v,u);
	}
}
void check() {
	int cnt=0;
	for(int i=1; i<=n; i++) mk[i]=0;
	for(int i=1; i<=n; i++) {
		if(is[i]&&!mk[i]) {
			dfs2(i,-1);
			cnt++;
		}
	}
	vector<int> vec;
	for(int i=1; i<=n; i++) if(is[i]) vec.push_back(i);
	if(cnt>2) return;
	ll mx=0,mn;
	for(int i=1; i<=n; i++) {
		mn=inf;
		for(int u:vec) {
			mn=min(mn,dis[i][u]);
		}
		mx=max(mn,mx);
	}
	ans=min(ans,mx);
}
void dfs(int i,int num) {
	if(!num) {
		check();
		return;
	}
	if(num>n-i+1||i>n) return;
	is[i]=1;
	dfs(i+1,num-1);
	is[i]=0;
	dfs(i+1,num);
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			is[i]=0;
			g[i].clear();
		}
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=inf;
		if(n<=10) {
			for(int rt=1; rt<=n; rt++) {
				dis[rt][rt]=0;
				dfs1(rt,rt,-1);
			}
			dfs(1,k);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

*/