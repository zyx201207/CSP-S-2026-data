#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+10+510,inf=4e18;
ll c,n,m,d,q,w[N],k[510],a[510][N],t[510][N],ans[N],vis[N];
vector<pair<int,ll> >G[N];
ll dis(int s,int e){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
	for(int i=1;i<=n+m;i++) ans[i]=inf,vis[i]=0;
	pq.push({0,s});
	ans[s]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto _:G[u]){
			int v=_.first;
			ll w=_.second;
			if(ans[u]+w<ans[v]){
				ans[v]=ans[u]+w;
				pq.push({ans[v],v});
			}
		}
	}
	return ans[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back({m+i,t[i][j]});
			G[m+i].push_back({a[i][j],t[i][j]});
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=w[x]+w[y]+dis(x,y);
		cout<<ans<<'\n';
	}
	return 0;
} 
//地铁口其实没有用可以舍弃不看 
//站厅为一个地铁站的“中心点”，附属点为某条地铁线的站台或者地铁口 
//可以把每一条线看作是一个超级源点，边权为0连向线路中每一个点（中心点的附属点）
//让t成为链接源点和普通点的边 


/*
1.处理超级源点
2.在n个超级源点之间跑最短路:
3.呜呜想到正解不敢写 
*/
