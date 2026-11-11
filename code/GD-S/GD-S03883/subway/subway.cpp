#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int M=5e5+10;
const int INF=1e17;
struct node{
	int id,w;
};
struct edge{
	int v,w;
	bool operator<(const edge other)const{
		return other.w<w;
	} 
};
vector<node> g_1[M];
vector<edge> g[N];
int min_dis[N][N],dis[N][N],a[M];
int c,n,m,d,q;
priority_queue<edge> pq;
void solve(int st){
	dis[st][st]=0;
	pq.push({st,0});
	while(!pq.empty()){
		int u=pq.top().v;
		int d=pq.top().w;
		pq.pop();
		if(d!=dis[st][u])continue;
		for(auto x:g[u]){
			if(d+x.w<dis[st][x.v]){
				dis[st][x.v]=d+x.w;
				pq.push({x.v,d+x.w});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)min_dis[i][j]=dis[i][j]=INF; 
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;cin>>u>>t;
			g_1[u].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:g_1[i]){
			for(auto v:g_1[i]){
				if(u.id==v.id)continue;
				min_dis[u.id][v.id]=min(min_dis[u.id][v.id],u.w+v.w);
				min_dis[v.id][u.id]=min(min_dis[v.id][u.id],u.w+v.w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||min_dis[i][j]==INF)continue;
			g[i].push_back({j,min_dis[i][j]});
		}
	} 
	for(int i=1;i<=n;i++)solve(i);
	while(q--){
		int st,ed;
		cin>>st>>ed;
		int res=INF;
		for(auto u:g_1[st]){
			for(auto v:g_1[ed])res=min(res,dis[u.id][v.id]+u.w+v.w);
		}
		cout<<res+a[st]+a[ed]<<"\n";
	}
	return 0;
}
