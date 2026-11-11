#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
using ll=long long;
int c,n,m,d,q;
ll m,n,a[505][N],w[N],t[505][N],k,dis[N][N];
struct node{
	int v,id;
};
vector<node>g[N];
void dj(int u,int i){
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push_back({{0,u},i});
	while(pq.size()){
		pii np=pq.top();
		pq.pop();
		int u=np.first.second,id=mp.second.second;
		ll s=np.first.first;
		if(vis[u]) continue;
		for(auto it:g[u]){
			int v=it.first,idv=it.second;
			if(dis[u][v]>s+)
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k;j++){
			g[a[i][j-1]].push_back({a[i][j],i});
		}
	}
	for(int i=1;i<=n;i++){
		dj(a[i][1]);
		claer();
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dj(x,y);
	}
	return 0;
}
