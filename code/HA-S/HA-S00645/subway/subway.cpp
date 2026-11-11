#include<bits/stdc++.h>
using namespace std;
const int N=5.5e5;
#define ll long long
ll c,n,m,d,Q,flag;
ll w[N];
struct node{
	ll v,w;
	bool operator<(const node &c)const{
		return w>c.w;
	}
};
vector<node> to[N];
void add(ll u,ll v,ll w){
	to[u].push_back({v,w});
	to[v].push_back({u,w});
}
struct QT{
	ll u,v,ans,id;
}qq[N];
bool cmp(QT x,QT y){
	return x.u<y.u;
}
ll dis[N],vis[N];
priority_queue<node> q;
void dijkstra(ll s){
	for(int i=1;i<=m+n;i++)dis[i]=3e18,vis[i]=0;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		ll u=q.top().v;
		q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(int i=0;i<to[u].size();i++){
			ll v=to[u][i].v,w=to[u][i].w;
			if(vis[v])continue;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
void bfs(ll s){
	queue<ll> q;
	for(int i=1;i<=m+n;i++)dis[i]=3e18,vis[i]=0;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		for(int i=0;i<to[u].size();i++){
			ll v=to[u][i].v,w=to[u][i].w;
			if(vis[v])continue;
			vis[v]=1;
			dis[v]=dis[u]+w;
			q.push(v);
		}
	}
}
bool cmp2(QT x,QT y){
	return x.id<y.id;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		ll s;
		scanf("%lld",&s);
		while(s--){
			ll a,t;
			scanf("%lld%lld",&a,&t);
			if(flag==0)flag=t;
			else if(flag!=t)flag=-1;
			add(a,m+i,t);
		}
	}
	for(int i=1;i<=Q;i++){
		scanf("%lld %lld",&qq[i].u,&qq[i].v);
		qq[i].id=i;
		if(qq[i].u>qq[i].v)swap(qq[i].u,qq[i].v);
	}
	sort(qq+1,qq+Q+1,cmp);
	for(int i=1;i<=Q;i++){
		if(flag!=-1)bfs(qq[i].u);
		else dijkstra(qq[i].u);
		do{
			qq[i].ans=dis[qq[i].v]+w[qq[i].u]+w[qq[i].v];
			i++;
		}while(qq[i].u==qq[i-1].u);
		i--;
	}
	sort(qq+1,qq+Q+1,cmp2);
	for(int i=1;i<=Q;i++)printf("%lld\n",qq[i].ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

