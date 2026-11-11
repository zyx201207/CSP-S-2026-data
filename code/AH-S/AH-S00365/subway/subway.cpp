#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+505;
const ll INF=0x3f3f3f3f3f3f;
int c,n,m,d,q;
ll dist[505][505];
ll w[N];
vector<int> node[N];
struct edge{
	int v;
	ll value;
};
vector<edge> color[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dist,INF,sizeof dist);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,v;
		ll t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>t;
			color[v].push_back({i,t});
			node[i].push_back(v);
		}
	}
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto [start,value1]:color[i]){
			for(auto [to,value2]:color[i]){
				if(start!=to){
					dist[start][to]=min(dist[start][to],value1+value2);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		ll ans=INF;
		cin>>u>>v;
		for(auto [start,value1]:color[u]){
			for(auto [to,value2]:color[v]){
				ans=min(ans,w[u]+w[v]+dist[start][to]+value1+value2);
			}
		}
		cout<<ans<<'\n';
	}
}
