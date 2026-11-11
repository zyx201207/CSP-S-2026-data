#include<bits/stdc++.h>
using namespace std;
#define int long
const int N=505,M=5e5+5;
int c,n,m,d,q,cnt;
bool vis[N];
int w[M],k[N],t[N][N],a[M],p[N][N],z[N][N];
vector<pair<int,int> > g[N];
void topo(int u,int fa,int fx,int y){
	if(fa==y) return ;
	vis[u]=1;
	for(auto h:g[u]){
		int v=h.first,x=h.second;
		if(v==fa&&vis[v]) continue;
		if(fx==x){
//			cout<<fx<<" "<<x<<"\n";
			p[u][v]+=t[x][v];
		}else{
			p[u][v]+=t[x][u]+t[x][v];
			fx=x;
		}
//		cout<<u<<" "<<v<<" "<<p[u][v]<<"\n";
		topo(v,u,fx,y);
	}
}
void pj(int u,int ex){
	for(auto h:g[u]){
		int v=h.first;
		if(p[u][v]!=0&&p[v][ex]!=0){
			p[u][ex]=p[u][v]+p[v][ex];
//			cout<<u<<" "<<v<<" "<<ex<<"\n";
//			cout<<p[u][v]<<" "<<p[v][ex]<<"\n";
		}
		else if(p[u][v]==0) pj(u,v);
		else if(p[v][ex]==0) pj(v,ex);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//ting
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];cnt++;
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[cnt][a[j]];
		}
		for(int j=2;j<=k[i];j++){
			g[a[j-1]].push_back({a[j],cnt});
//			g[a[j]].push_back({a[j-1],cnt});
		}
	}
//	for(auto h:g[1]){
//		cout<<h.first;
//	}
	while(q--){
		int x,y;cin>>x>>y;
		if(p[x][y]!=0){
			cout<<p[x][y]+w[x]+w[y]<<"\n";
			continue;
		}
		topo(x,0,-1,y);
		if(p[x][y]!=0){
			cout<<p[x][y]+w[x]+w[y]<<"\n";
			continue;
		}
		pj(x,y);
		cout<<p[x][y]+w[x]+w[y]<<"\n";
	}
	
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
