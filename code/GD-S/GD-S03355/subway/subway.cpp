#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
int w[M];
struct Edge{
	int to;
	ll val;
};
vector<int> g[M];
int t[N][M],a[N][M],vis[M],dis[M];
void dij(int s,int r){
	memset(dis,0x3f,sizeof(dis));
	vis[s]=1;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;
	dis[s]=t[r][s];
	pq.push({t[r][s],s});
	while(pq.size()){
		int u=pq.top().second;
		for(const auto&v:g[u]){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j==1)continue;
			g[i].push_back(i-1);
			g[i-1].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int cost=w[x]+w[y];
		for(int i=1;i<=n;i++){
			if(t[i][s]!=0){
				dij(x,i);
			}
		}
	}
	return 0;
}
