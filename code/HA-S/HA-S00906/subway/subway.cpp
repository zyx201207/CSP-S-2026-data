#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<utility>
#include<queue>
#define fileio(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define mems(x,v) memset(x,v,sizeof(x))
using namespace std;
namespace BaoTx{
	using ll=long long;
	using pii=pair<int,int>;
	using pli=pair<ll,int>;
	const int cN=502,cM=5e5+5,D=22;
	const ll INF=0x3f3f3f3f3f3f3f3fll;
	int c,n,m,d,q;
	int w[cM];
	pii l[cM][D];
	int cnt[cM];
	ll g[cN][cN];
	ll dis[cN][cN];
	
	priority_queue<pli>p;
	bool vis[cN];
	
	const int N=cN,M=cN*cN*2;
	int hd[N],to[M],nxt[M],num=1;
	ll vl[M];
	void add(int u,int v,ll w){
//		cout<<u<<v<<w<<"\n";
		num++;
		to[num]=v;
		vl[num]=w;
		nxt[num]=hd[u];
		hd[u]=num;
	}
	void main(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			while(k--){
				int v,t;
				cin>>v>>t;
				l[v][++cnt[v]]=make_pair(i,t);;
			}
		}
		mems(g,0x3f);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=cnt[i];j++){
				int u=l[i][j].first;
				ll ut=l[i][j].second;
				for(int k=j+1;k<=cnt[i];k++){
					int v=l[i][k].first;
					ll vt=l[i][k].second;
					g[u][v]=min(g[u][v],ut+vt);
					g[v][u]=min(g[v][u],ut+vt);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(g[i][j]<INF) add(i,j,g[i][j]);
//				if(g[i][j]==INF) cout<<"INF ";
//				else cout<<g[i][j]<<" ";
			}
//			cout<<endl;
		}
		mems(dis,0x3f);
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++) vis[i]=0;
			dis[k][k]=0;
			p.push(make_pair(0,k));
			while(!p.empty()){
				int u=p.top().second;
				p.pop();
				if(vis[u]) continue;
				vis[u]=true;
				for(int i=hd[u];i;i=nxt[i]){
					int v=to[i];
					if(dis[k][u]+vl[i]<dis[k][v]){
						dis[k][v]=dis[k][u]+vl[i];
						p.push(make_pair(-dis[k][v],v));
					}
				}
//				for(int v=1;v<=n;v++){
//					if(dis[k][u]+g[u][v]<dis[k][v]){
//						dis[k][v]=dis[k][u]+g[u][v];
//						p.push(make_pair(-dis[k][v],v));
//					}
//				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(dis[i][j]==INF) cout<<"INF ";
//				else cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=INF;
			for(int i=1;i<=cnt[x];i++){
				int u=l[x][i].first;
				ll ut=l[x][i].second;
				for(int j=1;j<=cnt[y];j++){
					int v=l[y][j].first;
					ll vt=l[y][j].second;
					ans=min(ans,dis[u][v]+ut+vt);
				}
			}
			ans+=w[x]+w[y];
			cout<<ans<<"\n";
		}
	}
}
int main(){
	fileio(subway);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	BaoTx::main();
	return 0;
}// 1610 1645