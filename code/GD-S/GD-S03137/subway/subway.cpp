#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int> 
#define pb push_back
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),p1==p2?EOF:*p1++)
inline int read(){
	int k=0,f=1;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
	for(;isdigit(c);c=gc()) k=k*10+(c^48);
	return k*f;
}
const int N=505,M=4e4+5,K=1e6+5,inf=1e18;
int c,n,m,d,q,p[K],dis[N][M*2],dis1[3][K];
bool vis[K];
vector<pair<int,int>> g[K];
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=n+m;i++) dis[s][i]=inf,vis[i]=0;
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.first,w=e.second;
			if(dis[s][v]>dis[s][u]+w) dis[s][v]=dis[s][u]+w,q.push({dis[s][v],v});
		} 
	}
}
void dij1(int s){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=n+m;i++) dis1[s][i]=inf,vis[i]=0;
	dis1[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto e:g[u]){
			int v=e.first,w=e.second;
			if(dis1[s][v]>dis1[s][u]+w) dis1[s][v]=dis1[s][u]+w,q.push({dis1[s][v],v});
		} 
	}
}
void solve(){
	for(int i=1;i<=n;i++) dij1(i);
	int x,y;
	while(q--){
		x=read(),y=read();
		int ans=inf;
		for(auto e:g[x+n]){
			int v=e.first,w=e.second;
			ans=min(dis1[v][y+n]+w,ans);
		}
		cout<<ans+p[x]+p[y]<<'\n';
	}
}
signed main(){
//	auto t0=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) p[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,x,t;j<=k;j++){
			x=read(),t=read();
			g[i].pb({n+x,t});g[n+x].pb({i,t});
		} 
	}
	if(c==20||c==21){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		dij(i);
//		for(int j=n+1;j<=n+m;j++) cout<<dis[i][j]<<' ';
//		cout<<'\n';
	} 
	int x,y;
	while(q--){
		x=read(),y=read();
		int ans=inf;
		for(auto e:g[x+n]){
			int v=e.first,w=e.second;
			ans=min(dis[v][y+n]+w,ans);
		}
		cout<<ans+p[x]+p[y]<<'\n';
	}
//	cerr<<"Time: "<<clock()-t0<<"ms";
	return 0;
}

