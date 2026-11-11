#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
//c 测试点编号  n 线路数  m 站数  d换乘站线路最多数  q询问数 
//wi 地铁口去站厅  ki 第i条线的规模  aij 第i线经过第j站  tij 第j站走到i线站台时间
//x 起点编号  y 终点编号
//1~8 12~15
const ll N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q;
ll k,a,t;
int x,y;
ll cost[M],ans;
bool vis[M];
struct node{
	ll w,w2[N];
	vector<pll>ve;
};
node sta[20005];
vector<int>lins[N];
ll dij(int sx,int sy){
	for(int i=1;i<=m;i++) cost[i]=INF,vis[i]=0;
	cost[sx]=0;
	priority_queue<pll,vector<pll>,greater<pll>>q;
	q.push({0,sx});
	while(!q.empty()){
		pll o=q.top();
		ll u=o.se;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:sta[u].ve){//遍历线路，fi 线路  se 站厅到站台时间 
			for(auto j:lins[i.fi]){
				if(u==j) continue;
				ll dis=cost[u]+i.se+sta[j].w2[i.fi];
				if(dis<cost[j]){
					cost[j]=dis;
					q.push({dis,j});
					if(j==sy) return cost[sy];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>sta[i].w;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			lins[i].push_back(a);
			sta[a].ve.push_back({i,t});
			sta[a].w2[i]=t;
		}
	}
	while(q--){
		cin>>x>>y;
		ans=sta[x].w+sta[y].w;
		cout<<ans+dij(x,y)<<"\n";
	}
	return 0;
}
