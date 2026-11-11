#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,r,i,j,l,x,y,ans,k,vis[502],
	w[500002],a[500002],t[500002];
struct o{int v,w;};vector<o>g[502];
struct b{
	int u,t;
	bool operator<(const b&h)
		const{return t>h.t;}
}p;
priority_queue<b>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>r;
	for(i=0;++i<=m;) cin>>w[i];
	for(i=0;i++<n;){
		cin>>k;
		for(j=0;++j<=k;)
			cin>>a[j]>>t[j];
		for(j=0;++j<=k;)
			for(l=0;++l<=k;) if(j!=l)
				g[a[j]].push_back({a[l],t[j]+t[l]});
	}
	while(r--){
		cin>>x>>y;
		while(q.size()) q.pop();
		q.push({x,0}),ans=1e9;
		memset(vis,63,sizeof vis);
		while(q.size()){
			p=q.top(),q.pop();
			if(vis[p.u]<=p.t) continue;
			//printf("Visit #%d, used %d steps.\n",p.u,p.t);
			if(vis[p.u]=p.t,p.u==y)
				ans=min(ans,p.t+w[x]+w[y]);
			for(o&v:g[p.u])
				q.push({v.v,p.t+v.w});
		}
		cout<<ans<<'\n';
	}
}
