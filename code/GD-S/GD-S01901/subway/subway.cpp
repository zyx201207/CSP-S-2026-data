#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i=(l);i<=(r);i++)
#define per(i,l,r) for (int i=(r);i>=(l);i--)

using namespace std;

const int inf=0x3f3f3f3f3f3f3f3f;

int c,n,m,d,q;

namespace Solve1 {
	const int N=510,M=1010;
	
	int w[M];
	int dis[N][M+N];
	bool vis[M+N];
	
	vector<pair<int,int>> e[N+M];
	
	void addEdge(int u,int v,int len){
//		printf("eg %lld %lld %lld\n",u,v,len);
		e[u].emplace_back(v,len);
		e[v].emplace_back(u,len);
	}
	
	void genshin(int s,int dis[]){
		memset(vis,0,sizeof(vis));
		fill(dis+1,dis+n+m+1,inf);
		priority_queue<pair<int,int>> q;
		q.emplace(0,s), dis[s]=0;
		
		while(q.size()){
			int u=q.top().second;
			q.pop();
//			printf("u:%lld\n");
			if(vis[u]) continue;
			vis[u]=1;
			for(auto eg : e[u]){
				int v=eg.first, len=eg.second;
//				printf("v:%lld\n",v);
				if(dis[v]<=dis[u]+len) continue;
				dis[v]=dis[u]+len;
				q.emplace(-dis[v],v);
			}
		}
		
//		printf("dis:");
//		rep(i,1,n+m) cout<<dis[i]<<" ";
//		puts("");
	}
	
	void solve(){
		rep(i,1,m) cin>>w[i];
		rep(i,1,n) {
			int k,a,t;
			cin>>k;
			rep(j,1,k){
				cin>>a>>t;
				addEdge(i+m,a,t);
			}
		}
		
		rep(i,1,n){
			genshin(i+m,dis[i]);
		}
		
		rep(i,1,q){
			int x,y;
			cin>>x>>y;
			int ans=inf;
			rep(i,1,n){
				ans=min(ans,dis[i][x]+dis[i][y]);
			}
			cout<<ans+w[x]+w[y]<<"\n";
		}
	}
}

namespace Solve2 {
	const int N=5,M=5e5+10;
	
	int w[M];
	int dis[N][M+N];
	bool vis[M+N];
	
	vector<pair<int,int>> e[N+M];
	
	void addEdge(int u,int v,int len){
//		printf("eg %lld %lld %lld\n",u,v,len);
		e[u].emplace_back(v,len);
		e[v].emplace_back(u,len);
	}
	
	void genshin(int s,int dis[]){
		memset(vis,0,sizeof(vis));
		fill(dis+1,dis+n+m+1,inf);
		priority_queue<pair<int,int>> q;
		q.emplace(0,s), dis[s]=0;
		
		while(q.size()){
			int u=q.top().second;
			q.pop();
//			printf("u:%lld\n");
			if(vis[u]) continue;
			vis[u]=1;
			for(auto eg : e[u]){
				int v=eg.first, len=eg.second;
//				printf("v:%lld\n",v);
				if(dis[v]<=dis[u]+len) continue;
				dis[v]=dis[u]+len;
				q.emplace(-dis[v],v);
			}
		}
		
//		printf("dis:");
//		rep(i,1,n+m) cout<<dis[i]<<" ";
//		puts("");
	}
	
	void solve(){
		rep(i,1,m) cin>>w[i];
		rep(i,1,n) {
			int k,a,t;
			cin>>k;
			rep(j,1,k){
				cin>>a>>t;
				addEdge(i+m,a,t);
			}
		}
		
		rep(i,1,n){
			genshin(i+m,dis[i]);
		}
		
		rep(i,1,q){
			int x,y;
			cin>>x>>y;
			int ans=inf;
			rep(i,1,n){
				ans=min(ans,dis[i][x]+dis[i][y]);
			}
			cout<<ans+w[x]+w[y]<<"\n";
		}
	}
}

namespace Solve3 {
	const int N=510,M=5e5+10;
	
	int w[M];
	int dis[M+N];
	
	vector<int> e[N+M];
	
	void addEdge(int u,int v){
//		printf("eg %lld %lld\n",u,v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	
	void Isaac(int s){
		fill(dis+1,dis+n+m+1,inf);
		queue<int> q;
		q.emplace(s), dis[s]=0;
		
		while(q.size()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				if(dis[v]<=dis[u]+1) continue;
				dis[v]=dis[u]+1;
				q.emplace(v);
			}
		}
		
//		printf("dis:");
//		rep(i,1,n+m) cout<<dis[i]<<" ";
//		puts("");
	}
	
	void solve(){
		rep(i,1,m) cin>>w[i];
		int T=0;
		rep(i,1,n) {
			int k,a,t;
			cin>>k;
			rep(j,1,k){
				cin>>a>>t;
				T=t;
				addEdge(i+m,a);
			}
		}
		
		rep(i,1,q){
			int x,y;
			cin>>x>>y;
			Isaac(x);
			int ans=dis[y];
			cout<<ans*T+w[x]+w[y]<<"\n";
		}
	}
}

signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	if(c<=11) Solve1::solve();
	else if(c>=20&&c<=21) Solve2::solve();
	else Solve3::solve();
	
	return 0;
}
