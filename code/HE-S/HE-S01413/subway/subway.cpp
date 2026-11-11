// 样例解释是奶龙写的吗？ 
#include<bits/stdc++.h>
#define int long long //别爆 
using namespace std;
const int N=500+5,M=5e5+5;
bool st;
int c,n,m,d,q,w[M],dis[N][N],vs[N],tim;
vector<pair<int,int> >e[M],lk[M];
bool ed;
void dij(int s){
	++tim;
	for(int i=1;i<=n;i++)dis[s][i]=1e18;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s}),dis[s][s]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vs[u]==tim)continue;
		vs[u]=tim;
		for(auto it:lk[u]){
			int v=it.first,w=it.second;
			if(dis[s][v]>dis[s][u]+w)dis[s][v]=dis[s][u]+w,q.push({dis[s][v],v});
		}
	}
}
#undef int 
int main(){
#define int long long 
	ios::sync_with_stdio(0),cin.tie(0); 
//	cerr<<(&ed-&st)/8/1024.0/1024.0<<'\n';  这么小 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){	
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	// d<=20这里应该不会爆 
	for(int i=1;i<=m;i++){
		int o=e[i].size();
		for(int j=0;j<o;j++){
			int u=e[i][j].first,w1=e[i][j].second;
			for(int k=j+1;k<o;k++){
				int v=e[i][k].first,w2=e[i][k].second;
				lk[u].push_back({v,w1+w2});
				lk[v].push_back({u,w1+w2}); // 重边影响复杂度吗 
			}
		}
	} 
	// 我猜边数不会很多 
	for(int i=1;i<=n;i++)dij(i);
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int ans=1e18;
		int o1=e[x].size(),o2=e[y].size();
		for(int j=0;j<o1;j++){
			for(int k=0;k<o2;k++){
				int u=e[x][j].first,w1=e[x][j].second;
				int v=e[y][k].first,w2=e[y][k].second;
				ans=min(ans,w[x]+w[y]+dis[u][v]+w1+w2);
//				ans=min(ans,w[x]+w[y]+W[x][vt[x][j]]+W[y][vt[y][k]]+dis[vt[x][j]][vt[y][k]]);
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
