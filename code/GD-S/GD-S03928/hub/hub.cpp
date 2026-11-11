#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
int c,t,n,k,x,y,ans;
bitset<N> p,p2,o;
vector<int> G[N];
inline void init() {
	ans=1e9;
	for(int i=1;i<=n;i++)
		G[i].clear();
}
void dfs2(int x) {
	for(auto v:G[x]) {
		if(p[v]&&!p2[v]) {
			p2[v]=1;
			dfs2(v);
		}
	}
}
int dfs3(int x,int fa,int dis) {
	int mi=1e9;
	if(p[x])return dis;
	for(auto v:G[x]) {
		if(v!=fa)
			mi=min(mi,dfs3(v,x,dis+1));
	}return mi;
}
inline void solve() {
	p2=o;
	int sum=0,ma=0;
	for(int i=1;i<=n;i++)
		if(p[i]&&!p2[i]) {
			dfs2(i);
			sum++;
		}
	if(sum>2)return;
	for(int i=1;i<=n;i++) {
		if(p[i])continue;
		ma=max(ma,dfs3(i,0,0));
	}ans=min(ans,ma);
}
void dfs(int x,int s) {
	if(s==k) {
		solve();
		return;
	}
	if(x>n)return;
	p[x]=1;
	dfs(x+1,s+1);
	p[x]=0;
	dfs(x+1,s);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		init();
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
