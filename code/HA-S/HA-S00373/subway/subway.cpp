#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cc,n,m,dd,T;
ll c[500005],a[500005],b[500005],k,d[1000005],vis[1000005],idx=0;
struct str{
	ll v,w;
};
struct st{
	ll w,u;
	bool operator >(const st &other)const{
		return w>other.w;	
	}
};
vector<str> t[500005];
vector<str> g[1000005],g2[1000005];
void solve(){
	int s,e;
	cin>>s>>e;
	for(int i=0;i<=n*m+m+1;i++){
		d[i]=1e18;
		vis[i]=0;
	}
	for(int i=1;i<=n*m+m;i++){
		g2[i].clear();
		for(int j=0;j<g[i].size();j++){
			g2[i].push_back(g[i][j]);
		}
	}
	g2[0].clear(),g2[n*m+m+1].clear();
	for(int i=0;i<t[s].size();i++){
		ll w=t[s][i].w,flo=t[s][i].v;
		g2[0].push_back({(flo-1)*m+s,w});
		g2[(flo-1)*m+s].push_back({0,w});
	}
	for(int i=0;i<t[e].size();i++){
		ll w=t[e][i].w,flo=t[e][i].v;
		g2[(n+1)*m+1].push_back({(flo-1)*m+e,w});
		g2[(flo-1)*m+e].push_back({1+(n+1)*m,w});
	}
	priority_queue<st ,vector<st> ,greater<st> > q;
	d[0]=0;
	q.push({0,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g2[u].size();i++){
			int v=g2[u][i].v;
			ll w=g2[u][i].w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
	cout<<d[(n+1)*m+1]+a[s]+a[e]<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>dd>>T;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j]>>c[j];
			t[b[j]].push_back({i,c[j]});
			if(j>1){
				g[b[j]+(i-1)*m].push_back({b[j-1]+(i-1)*m,0});
				g[b[j-1]+(i-1)*m].push_back({b[j]+(i-1)*m,0});
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(t[i].size()<=1){
			continue;
		}
		for(int j=0;j<t[i].size();j++){
			ll w=t[i][j].w,flo=t[i][j].v;
			g[i+(n)*m].push_back({(flo-1)*m+i,w});
			g[(flo-1)*m+i].push_back({i+(n)*m,w});
		}
	}
	while(T--){
		solve();
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
1 3 5 3 3
1 2 3 4 5
4 1 5 2 1 3 1 4 1
3 1 2 3 2 5 3
3 3 3 4 3 5 2
1 3
3 5
1 2
*/
