#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
using ll=long long;
const int N=5e5+8;
struct p {
	ll a,b;
};
ll w[N],a[510][N],t[510][N];
ll c,n,m,d,q;
vector<p> f[N];
ll dfs(ll u,ll nw,ll v,ll x2) {
	if(u==x2){
		return v+t[nw][u]+w[u];
	}
	ll xv=v,mx=1e18+8;
	for(p s : f[u]) {
		if(s.b!=nw) {
			xv+=t[nw][u]+t[s.b][u];
		}
		xv+=dfs(s.a,s.b,xv,x2);
		mx=min(mx,xv);
	}
	v+=mx;
	return v;
}
int main(){
//	system("fc /w subway1.ans subway1.out");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(ll i=1; i<=n; i++) {
		ll k;
		cin>>k;
		for(ll j=1; j<=k; j++) {
			cin>>a[i][j];
			if(j>1) {
				f[a[i][j]].push_back({a[i][j-1],i});
			}
			cin>>t[i][a[i][j]];
		}
	}
	while(q--) {
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0; i<f[y].size(); i++) {
			ans=min(ans,dfs(y,f[y][i].b,w[y]+t[f[y][i].b][y],x));
		}
		cout<<ans<<endl;
	}
	return 0;
}
