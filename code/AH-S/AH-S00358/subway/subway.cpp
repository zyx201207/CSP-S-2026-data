#include <bits/stdc++.h>
using namespace std;
const int maxn = 500+10;
const int maxm = 5e5+10;
using ll = long long;

vector < pair<int,ll> > g[maxn+maxm];
void addedge(int x,int y,ll w){
	g[x].push_back({y,w});
	g[y].push_back({x,w});
}

struct DJI{
	vector<ll> dis;
	vector<bool> vis;
	
	using pli = pair<long long,int>;
	priority_queue< pli,vector<pli>,greater<pli> > q;
	
	DJI(int n,int x):dis(n+10,-1),vis(n+10,false){
		dis[x]=0;
		q.push({0,x});
		while(q.size()){
			int u=q.top().second;
			q.pop();
			//cout<<u<<" ";
			
			if(vis[u]) continue;
			vis[u]=1;
			for(auto to:g[u]){
				int v=to.first;
				ll w=to.second;
				//if(u==9){
					//cout<<v<<" "<<dis[v]<<" "<<dis[u]<<" "<<w<<"\n";
				//}
				if(dis[v] > dis[u]+w || dis[v]==-1){
					dis[v]=dis[u]+w;
					q.push({dis[v],v});
				}
			}
		}
	}
};

int c,n,m,d,q;
ll w[maxm];
namespace p1{
	
	void solve(){
		const int N = m+n+1;
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			for(int j=1;j<=k;j++){
				int x,t;
				cin>>x>>t;
				addedge(x,m+i,t);
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			DJI dji(N,x);
			/*
			cout<<"\n";
			for(int i=1;i<=N;i++) cout<<dji.dis[i]<<" ";
			cout<<"\n";
			* */
			cout<<dji.dis[y]+w[x]+w[y]<<"\n";
		}
	}
}

namespace p2{
	const int N = 1000+10;
	ll f[N][N];
	void solve(){
		//for(int i=1;i<=m;i++) f[i].assign(m+10,LONG_LONG_MAX),f[i][i]=0;
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=m;i++) f[i][i]=0;
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			ll x,y;
			ll xx,yy;
			if(k==1) cin>>x>>y;
			if(k==2){
				cin>>x>>xx>>y>>yy;
				f[x][y]=f[y][x]=min(f[x][y],xx+yy);
			}
		}
		
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<f[x][y] + w[x]+w[y]<<"\n";
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	if(c==0) p2::solve();
	else if(c<=6) p1::solve();
	else if(c<=11) p2::solve();
	return 0;
}
