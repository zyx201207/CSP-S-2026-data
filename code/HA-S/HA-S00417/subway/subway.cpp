#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=5e5+5,N=5e2+5;
long long w[M];
namespace task1to6{
	long long g[1010][1010];
	void solve(){
		for (int i=1;i<=n+m;i++) for (int j=1;j<=n+m;j++) g[i][j]=1e18;
		for (int i=1;i<=n+m;i++) g[i][i]=0;
		for (int i=1;i<=n;i++){
			int k;
			cin>>k;
			while (k--){
				int a;
				long long t;
				cin>>a>>t;
				g[a][m+i]=t;
				g[m+i][a]=t;
			}
		}
		for (int k=1;k<=n+m;k++){
			for (int i=1;i<=n+m;i++){
				for (int j=1;j<=n+m;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
		while (q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+g[x][y]+w[y]<<"\n";
		}
		cout<<endl;
	}
}
namespace task7to11{
	struct e{
		int v;
		long long w;
		bool operator<(const e o)const{
			return w>o.w;
		}
	};
	vector<pair<int,long long> > g[1010];
	long long dis[1010][1010];
	int vis[1010];
	priority_queue<e> qu;
	void dij(int s){
		memset(vis,0,sizeof(vis));
		qu.push({s,0});
		while (!qu.empty()){
			int u=qu.top().v;
			qu.pop();
			if (vis[u]) continue;
			vis[u]=1;
			for (int i=0;i<g[u].size();i++){
				pair<int,long long> p=g[u][i];
				int v=p.first;
				long long w=p.second;
				if (dis[s][u]+w<dis[s][v]){
					dis[s][v]=dis[s][u]+w;
					qu.push({v,dis[s][v]});
				}
			}
		}
	}
	void solve(){
		for (int i=1;i<=m;i++) for (int j=1;j<=n+m;j++) dis[i][j]=0x3f3f3f3f3f3f3f3f;
		for (int i=1;i<=m;i++) dis[i][i]=0;
		for (int i=1;i<=n;i++){
			int k;
			cin>>k;
			int a1,a2;
			long long t1,t2;
			cin>>a1>>t1>>a2>>t2;
			g[a1].push_back({a2,t1+t2});
			g[a2].push_back({a1,t1+t2});
		}
		for (int i=1;i<=m;i++) dij(i);
		while (q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+dis[x][y]+w[y]<<"\n";
		}
		cout<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	if (c<=6) task1to6::solve();
	else if (7<=c&&c<=11) task7to11::solve();
	return 0;
}
