#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
using ll= long long;
using ull= unsigned long long;
const int N=100005,inf=1000000000;
int n,k;
vector<int> g[N];
int dep[N],du,dv;
int ans,ret,rett;
inline void dfs(int u,int p) {
	dep[u]=dep[p]+1;
//	cerr<<u<<' '<<dep[u]<<'\n';
	ret=max(ret,dep[u]);
	for(int& v: g[u]) if(v^p) {
		if((u==du&&v==dv)||(v==du&&u==dv)) continue;
		dfs(v,u);
	}
}
inline void dfs1(int u,int p) {
	ret=-inf;
	dfs(u,0);
//	if(du==2&&dv==3) cerr<<u<<' '<<ret<<'\n';
	rett=min(rett,ret);
	for(int& v: g[u]) if(v^p) {
		if((u==du&&v==dv)||(v==du&&u==dv)) continue;
		dfs1(v,u);
	}
}
inline void mian() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int u,v,i=1;i<n;i++) {
		cin>>u>>v;
		g[u].pb(v),g[v].pb(u);
	}
	dep[0]=-1,ans=inf;
	if(k==1) {
		du=dv=0,rett=inf;
		dfs1(1,0);
		cout<<rett<<'\n';
		return;
	}
	if(k==2) {
		for(int u=1;u<=n;u++)
			for(int& v: g[u]) if(u<v) {
				du=u,dv=v;
				rett=inf;
				dfs1(u,0);
				int tm=rett;rett=inf;//if(u==2&&v==3) cerr<<'\n';
				dfs1(v,0);
				ans=min(ans,max(rett,tm));
			}
		cout<<ans<<'\n';
		return;
	}
	cout<<"bukeyizongsiling\n";
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,TwT=1;
	cin>>c>>TwT;
	while(TwT--) mian();
	return 0;
}

