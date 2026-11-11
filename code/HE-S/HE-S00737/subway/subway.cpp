#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N1=3e3+555,N=5e5+555;
ll c,n,m,d,q,dis[N1][N1],head[N],num;
ll cs[N];
struct Edge{
	ll to,next,val;
	bool operator < (const Edge p)const{
		return val<p.val;
	}
}e[N*4];
void adde(ll u,ll v,ll w){
	e[++num].to=v;
	e[num].next=head[u];
	e[num].val=w;
	head[u]=num;
}
bool vis[N];
queue<ll> q2;
void spfa(ll s){
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	q2.push(s);
	vis[s]=1;
	while(!q2.empty()){
		int u=q2.front();
		q2.pop();
		vis[u]=0;
		for(int i=head[u]; i; i=e[i].next){
			ll v=e[i].to,w=e[i].val;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				if(!vis[v]){
					vis[v]=1;
					q2.push(v);
				}
			}
		}
	}
//	for(int i=1; i<=n; i++) cout<<dis[s][i]<<' ';
//	cout<<"jjj\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&q);
	for(int i=1; i<=n; i++) scanf("%lld",&cs[i]);
	ll cn,ap,aq;
	for(int i=1; i<=m; i++){
		scanf("%lld",&cn);
		for(int j=1; j<=cn; j++){
			scanf("%lld%lld",&ap,&aq);
			adde(ap,n+i,aq);
			adde(n+i,ap,aq);
		}
	}
	for(int i=1; i<=n; i++) spfa(i);
	while(q--){
		scanf("%lld %lld",&ap,&aq);
		printf("%lld\n",dis[ap][aq]+cs[ap]+cs[aq]);
	}
	return 0;
}

