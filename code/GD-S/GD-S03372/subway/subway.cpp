#include<bits/stdc++.h>
#define _ti_mu (string)("subway")
#define tiaoshi 0
#define t_ if(tiaoshi)
using namespace std;
using ll = long long;using vi = vector<int>;
using pii = pair<int,int>;using vll = vector<ll>;
using ai3 = array<int,3>;
int c,n,m,d,q;
vll w(500005,0);
vector<pii> e[500005];
vector<ai3> g;
void edge(int u,int v,int w){
	e[u].push_back(make_pair(v,w));
	e[v].push_back(make_pair(u,w));
	g.push_back({u,v,w});
}
ll dist[5005][5005];
void floyd(int p){
	//build edge
	for(const ai3 i : g){
		int u=i[0],v=i[1],w=i[2];
		dist[u][v] = w;
		dist[v][u] = w;
	}
	//floyd
	for(int i = 1;i<=p;i++){
		for(int j = 1;j<=p;j++){
			if(i==j) continue;
			for(int k = 1;k<=p;k++){
				if(i==k||j==k) continue;
				if(dist[i][j]+dist[j][k]<dist[i][k]){
					dist[i][k]=dist[i][j]+dist[j][k];
				}
			}
		}
	}
}
int main(){
	freopen((_ti_mu+".in").c_str(),"r",stdin);
	freopen((_ti_mu+".out").c_str(),"w",stdout);
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;cin>>k;
		for(int j = 1;j<=k;j++){
			int a,t;cin>>a>>t;
			edge(i,n+a,t);
		}
	}
	//t_ printf("floyd begin\n");
	floyd(m+n);
	//t_ printf("floyd end\n");
	for(int _ = 1;_<=q;_++){
		int x,y;
		cin>>x>>y;
		ll ans = w[x]+w[y]+dist[n+x][n+y];
		cout<<ans<<endl;
	}
	return 0;
}
/* all of them *
dijkstra
floyd
SPFA
IDA*
A*
bfs
dfs
s**t f s
c* f s
*/
