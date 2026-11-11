#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5+5,M = 505;
const ll INF = 1e18+7;

struct node {
	int u,val;
};
int c,n,m,d,Q;
ll e[M][M];
ll w[N];
vector<node> g[N]; 
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>c>>n>>m>>d>>Q;
	
	for(int i=1;i<=m;i++) 
		cin>>w[i];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=INF;
	
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++) {
			int x,v;
			cin>>x>>v;
			g[x].push_back({i,v});
		}
	}
	
	for(int i=1;i<=m;i++) {
		for(int j=0;j<g[i].size();j++){
			int u=g[i][j].u,val=g[i][j].val;
			for(int k=j+1;k<g[i].size();k++) {
				int v=g[i][k].u;
				ll gx=val+g[i][k].val;
				e[u][v]=min(e[u][v],gx);
				e[v][u]=min(e[v][u],gx);
			}
		}
	}
	for(int i=1;i<=n;i++)
		e[i][i]=0;
	
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) 
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
		}
	}
	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<e[i][j]<<" \n"[j==n];
	while(Q--) {
		int x,y;
		cin>>x>>y;
		
		ll ans=INF;
		for(int i=0;i<g[x].size();i++) {
			int u=g[x][i].u;
			ll w1=g[x][i].val;
			for(int j=0;j<g[y].size();j++) {
				int v=g[y][j].u;
				ll w2=g[y][j].val;
//				cout<<u<<" "<<v<<'\n';
				ans=min(ans,e[u][v]+w1+w2);
			}
		}
		
		ans+=w[x]+w[y];
		cout<<ans<<'\n'; 
	}
	return 0;
} 
