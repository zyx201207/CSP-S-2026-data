#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l;i <= (r);i ++)
#define per(i,l,r) for(int i = l;i >= (r);i --)
#define pii pair<int,int>
#define fi fisrt
#define se second
const int N=5e5+5,INF=1e18;
int n,k,a[N],ans,t,f[N],g[N];
vector<int>e[N];
void check(int u,int fa) {
	t+=(a[u]==1&&a[fa]==0);
	for(int v:e[u]) if(v!=fa) check(v,u);
}
void s(int u,int fa) {
	for(int v:e[u]) if(v!=fa) {
		s(v,u);
		f[u]=min(f[v]+1,f[u]);
	}
	if(a[u]) f[u]=0;
}
void dfs(int x,int K) {
	if(K>k) return;
	if(x>n&&K<k) return;
	if(x>n) {
		t=0,check(1,0);
		if(t<=2) {
			int z=0;
			rep(i,1,n) {
				rep(j,1,n) f[j]=INF;
				s(i,0),z=max(z,f[i]);
			}
			ans=min(ans,z);
		}
		return ;
	}
	a[x]=0,dfs(x+1,K),a[x]=1,dfs(x+1,K+1);
}
void Solve() {
	cin >> n >> k,ans=INF;
	rep(i,1,n) e[i].clear();
	rep(i,2,n) {
		int u,v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	} 
	dfs(1,0);
	cout << ans << "\n";
	return ;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int dc=1,T=1,id;
	if(dc) cin >> id >> T;
	rep(i,1,T) Solve();
	return 0;
}

