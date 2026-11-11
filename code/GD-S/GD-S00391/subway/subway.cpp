#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
int C,n,m,D,Q;
int w[N];
int road[N][20];
int cost[N][20];
int cnt[N];
struct node{
	int to,nxt;
	ll w;
}e[500*500*2+7];
int h[507],ct;
inline void add(int u,int v,ll w){
	e[++ct]={v,h[u],w};
	h[u]=ct; 
}
struct Queue{
	ll dis;
	int u;
	bool operator>(const Queue &o)const{
		return dis>o.dis;
	}
};
priority_queue<Queue,vector<Queue>,greater<Queue> > q;
ll dis[507][507];
bool inq[507];
inline void dijstra(ll *dis,int rt){
	for(int i=1;i<=n;i++) dis[i]=INF;
	for(int i=1;i<=n;i++) inq[i]=0;
	dis[rt]=0;
	q.push({dis[rt],rt});
	while(!q.empty()){
		auto o=q.top();
		q.pop();
		int u=o.u;
		if(inq[u]) continue;
		inq[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({dis[v],v});
			}
		}	
	}
}
ll val[507][507];
inline int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		k=(k<<3)+(k<<1)+c-48;
		c=getchar();
	}return (f==-1?-k:k);
}
inline ll min(ll x,ll y){
	return x>y?y:x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	C=read(),n=read(),m=read(),D=read(),Q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) val[i][j]=INF;
		val[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read(),c=read();
			for(int o=0;o<cnt[x];o++)
				val[i][road[x][o]]=val[road[x][o]][i]=min(val[i][road[x][o]],1ll*cost[x][o]+c);
			road[x][cnt[x]]=i;
			cost[x][cnt[x]]=c;
			cnt[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			add(i,j,val[i][j]),add(j,i,val[i][j]);
	for(int i=1;i<=n;i++)
		dijstra(dis[i],i);
	while(Q--){
		int st=read(),ed=read();
		ll res=INF;
		for(int i=0;i<cnt[st];i++)
			for(int j=0;j<cnt[ed];j++)
				res=min(res,dis[road[st][i]][road[ed][j]]+cost[st][i]+cost[ed][j]);
		cout<<res+w[st]+w[ed]<<"\n";
	}return 0;
}
