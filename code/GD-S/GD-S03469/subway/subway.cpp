//时间在消逝 我们的故事开始
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+10;
int c,n,m,d,q;
int minn=1e18;
int w[M];
int vis[M];
struct ott {
	int p,t;
};
vector<ott> a[510];
vector<int> s[21];
void dfs(int p,int fn,int t) {
	int cr;
	if(vis[p]) return ;//cout<<p<<' '; 
	vis[p]=1;
	if(p==fn) {
		minn=min(t,minn);
		return ;
	}
	if(t>minn) return ;
	for(auto k:s[p]) {
		for(auto tmp:a[k]) 
			if(tmp.p==p) cr=tmp.t; 
		for(auto tmp:a[k]) {
				dfs(tmp.p,fn,t+tmp.t+cr);
		}
	}
	//vis[p]=0;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int p,t;
			cin>>p>>t;
			s[p].push_back(i);
			a[i].push_back({p,t});
		}
	}
	while(q--) {
		for(int i=1; i<=n; i++) vis[i]=0;
		minn=1e18;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+minn+w[y]<<'\n';
	}
	return 0;
}
