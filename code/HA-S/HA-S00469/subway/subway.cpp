#include<bits/stdc++.h>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
const int N=510;
bool vis[N];
struct nd{
	int _i;ll _x;
	bool operator<(const nd& y)const{
		return y._x<_x;
	}
}_u;
vector<int> g[N];
ll li[N][N],dis[N][N],w[N];
void add(int u,int v,ll va){
	if(!li[u][v])
		g[u].push_back(v);
	li[u][v]=min(li[u][v],va);
	dis[u][v]=li[u][v];
}int c,n,m,d,q;ll di[N];
queue<int> qu;
priority_queue<nd> pq;
void dijkstra(int x){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m;i++) di[i]=1e18;
	di[x]=0;pq.push({x,0});qu.push(x);
	for(int i=1;i<=m;i++){
		_u=pq.top();
		int u=_u._i;pq.pop();
		if(vis[u]) continue;
		vis[u]=1,dis[x][u]=di[u];
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(di[u]+li[u][v]<di[v]&&!vis[v]){
				di[v]=di[u]+li[u][v];
				pq.push({v,di[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&c);
	scanf("%d%d",&n,&m);
	scanf("%d%d",&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		ll a[30],t[30];
		for(int j=1;j<=k;j++){
			scanf("%lld",&a[j]);
			scanf("%lld",&t[j]);
			if(j!=1){
				add(a[j-1],a[j],t[j]+t[j-1]);
				add(a[j],a[j-1],t[j]+t[j-1]);
			}
		}
	}ll ans;
	for(int i=1,x,y;i<=q;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		if(!dis[x][y])
			dijkstra(x);
		printf("%lld\n",dis[x][y]+w[x]);
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

