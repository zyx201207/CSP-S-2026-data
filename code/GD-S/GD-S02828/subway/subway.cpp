#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005,M=505;
int bh,n,m,d,Q,k[M];
ll w[N+M];
vector<vector<ll>> f(N+M,vector<ll>(N+M,0x3f3f3f3f));
vector<vector<int>> z(N+M,vector<int>(N+M));
//vector<vector<pair<int,int>>> adj(N+M);
ll sum(int u,int v) {
	if(!z[u][v]) return w[u]+w[v];
	return sum(u,z[u][v])+sum(z[u][v],v)-w[z[u][v]];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>bh>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++) {
		cin>>w[i];//v站点权 
		/*
		adj[0].push_back({i,0});
		adj[i].push_back({i,0});
		*/
		f[i][i]=f[0][i]=0;
	}
	for(int i=1;i<=m;i++) {//i边 
		cin>>k[i];//i边经过站数 
		for(int j=1;j<=k[i];j++) {//a(i,j)
			int a,t;cin>>a>>t;
			/*
			adj[a].push_back({n+i,t});
			adj[n+i].push_back({a,0});
			*/
			f[a][n+i]=t,f[n+i][a]=0;
		}
	}
	/*
	for(int u=0;u<=n+m;u++) {
		int l=adj[u].size();
		cout<<l<<" ";
		for(int i=0;i<l;i++) {
			int v=adj[u][i].first,w=adj[u][i].second;
			cout<<" "<<v<<" "<<w<<" ";
		}
		cout<<"\n";
	}
	*/
	for(int k=1;k<=n+m;k++) {
		for(int i=0;i<=n+m;i++) {
			for(int j=1;j<=n+m;j++) {
//				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				if(f[i][k]+f[k][j]<f[i][j]) {
					f[i][j]=f[i][k]+f[k][j];
					z[i][j]=k;
				}
			}
		}
	}
	while(Q--) {
		int x,y;cin>>x>>y;
		cout<<sum(x,y)<<"\n";
	}
	
	return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005,M=505;
int bh,n,m,d,Q,w[N+M],k[M];
vector<vector<ll>> f(N+M,vector<ll>(N+M,0x3f3f3f3f));
//vector<vector<pair<int,int>>> adj(N+M);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	
	cin>>bh>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++) {
		cin>>w[i];//v站点权 
		/*
		adj[0].push_back({i,w[i]});
		adj[i].push_back({i,w[i]});
		//
		f[i][i]=w[i];
		f[0][i]=w[i];
	}
	for(int i=1;i<=m;i++) {//i边 
		cin>>k[i];//i边经过站数 
		for(int j=1;j<=k[i];j++) {//a(i,j)
			int a,t;cin>>a>>t;
			/*
			adj[a].push_back({n+i,t+w[a]});
			adj[n+i].push_back({a,w[a]});
			//
			f[a][n+i]=t+w[a],f[n+i][a]=w[a];
		}
	}
	/*
	for(int u=0;u<=n+m;u++) {
		int l=adj[u].size();
		cout<<l<<" ";
		for(int i=0;i<l;i++) {
			int v=adj[u][i].first,w=adj[u][i].second;
			cout<<" "<<v<<" "<<w<<" ";
		}
		cout<<"\n";
	}
	//
	for(int k=1;k<=n+m;k++) {
		for(int i=0;i<=n+m;i++) {
			for(int j=1;j<=n+m;j++) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]-w[k]);
			}
		}
	}
	while(Q--) {
		int x,y;cin>>x>>y;
		cout<<f[x][y]<<"\n";
	}
	
	return 0;
}
*/
