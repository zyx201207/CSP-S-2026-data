//胡景涵 GZ-S00175 贵阳市第三中学 
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int M=5e5+10,N=500+10;
int c,n,m,d,q,tot,altot;
int w[M],id[M],dist[N+M],proc[N][N]; 
vector< pii > g[N+M];
vector<int> fa[M];
map<int,int> t[N];

void dij(int st){
	for(int i=1;i<=tot;i++) dist[i]=LONG_LONG_MAX;
	for(int i=m+1;i<=m+n;i++) dist[i]=LONG_LONG_MAX;
	dist[st]=0;
	priority_queue< pii , vector< pii >, greater<pii> > q;
	q.push({0,st});
	while(q.size()){
		auto p=q.top(); q.pop();
		int d=p.first,u=p.second;
		if(dist[u]<d) continue;
		if(u>m) proc[st-m][u-m]=dist[u];
		for(auto e:g[u]){
			int c=e.first,v=e.second;
			if(dist[u]+c<dist[v]){
				dist[v]=dist[u]+c;
				q.push({dist[v],v});
			}
		}
	}
}
// fc /w subway.out subway6.ans
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	
	freopen("subway.in","r",stdin); freopen("subway.out","w",stdout);
	//换乘点用tot，线路点用i+m 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int st,tim;
			cin>>st>>tim;
			fa[st].push_back(i);
			t[i][st]=tim;
		}
	}
	
	for(int i=1;i<=m;i++){
		if(fa[i].size()>1){
			tot++; id[tot]=i; //用i找tot 
			for(int lines : fa[i]){//经过这个站的所有线路 
				g[lines+m].push_back({t[lines][i],tot});
				g[tot].push_back({t[lines][i],lines+m});
			}
		}
	}
	for(int i=m+1;i<=m+n;i++){
		dij(i);
	}
	while(q--){
		int u, v;
		cin>>u>>v;
		int ans=LONG_LONG_MAX;
		for(int sl:fa[u]){
			for(int el:fa[v]){
				ans=min(w[u]+w[v]+t[sl][u]+t[el][v]+proc[sl][el],ans);
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
