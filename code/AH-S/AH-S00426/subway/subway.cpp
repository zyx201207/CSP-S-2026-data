#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10,M=5e5+10,D=5e5+10;
LL c,n,m,d,q,w[M],k[505],dis[10005][10005],dis2[M];
int a[505][10005],t[505][10005];
bool vis[M];
struct Node{
	LL u,ti;
	bool operator<(const Node& rhs)const{
		return rhs.ti<ti;
	}
};
vector<Node> G[N],f[N];
void djs(LL x){
	memset(vis,0,sizeof vis);
	priority_queue<Node> pq;
	pq.push({x,0});
	dis[x][x]=0;
	while(!pq.empty()){
		Node u=pq.top();pq.pop();
		vis[u.u]=1;
		for(Node v:G[u.u]){
			if(!vis[v.u]&&dis[x][v.u]>dis[x][u.u]+v.ti){
				dis[x][v.u]=dis[x][u.u]+v.ti;
				pq.push({v.u,dis[x][v.u]});
			}
		}
	}
}
void djs2(LL x){
	memset(dis2,0x3f,sizeof dis2);
	memset(vis,0,sizeof vis);
	priority_queue<Node> pq;
	pq.push({x,0});
	dis2[x]=0;
	while(!pq.empty()){
		Node u=pq.top();pq.pop();
		vis[u.u]=1;
		for(Node v:G[u.u]){
			if(!vis[v.u]&&dis2[v.u]>dis2[u.u]+v.ti){
				dis2[v.u]=dis2[u.u]+v.ti;
				pq.push({v.u,dis2[v.u]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof dis);
	for(LL i=1;i<=m;++i)	scanf("%lld",&w[i]);
	for(LL i=1;i<=n;++i){
		scanf("%lld",&k[i]);
		for(LL j=1;j<=k[i];++j){
			scanf("%d%d",&a[i][j],&t[i][j]);
			f[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(LL i=1;i<=m;++i){//i--车站
		for(Node j:f[i]){	//j--路线
			for(LL p=1;p<=k[j.u];++p){ //a[j.u][p]--邻接点车站
				if(a[j.u][p]==i)	continue;
				G[i].push_back({a[j.u][p],t[j.u][p]+j.ti});
				G[a[j.u][p]].push_back({i,t[j.u][p]+j.ti});
			}
		}
	}
	if(m*m<=1e8)	for(LL i=1;i<=m;++i)	djs(i);
	for(LL r=1;r<=q;++r){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if(m*m<=1e8)	printf("%lld\n",dis[x][y]+w[x]+w[y]);
		else djs2(x),printf("%lld\n",dis2[y]+w[x]+w[y]);
	}
	return 0;
}
