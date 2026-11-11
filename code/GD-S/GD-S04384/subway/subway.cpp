#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int N(5e2+5),M(1e3+N);
int c,n,m,d,q;
int w[M],k[M];
int a[N][M],t[N][M],dis[M][M];
vector<pair<int,int>>e[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k[i];++j){
			e[a[i][j]].push_back({m+i,t[i][j]});
			e[m+i].push_back({a[i][j],t[i][j]});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;++i){
		dis[i][i]=0;
		pq.push({0,i});
		while(pq.size()){
			int t(pq.top().F),u(pq.top().S);
			pq.pop();
			if(t>dis[i][u]) continue;
			for(auto[v,w]:e[u]){
				if(t+w<dis[i][v]){
					dis[i][v]=t+w;
					pq.push({t+w,v});
				}
			}
		}
	}
	for(int x,y;q--;){
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<'\n'; 
	}		
}
