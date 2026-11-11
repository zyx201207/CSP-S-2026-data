#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+500,M=2e6;
int c,n,m,d,q,h[M],ct;
ll w[N],sum,dis[N];
bool ch[N];
struct edge{
	int u,v,nxt;
	ll val;
}e[M];
struct node{
	ll ds ;int id;
	bool operator <(const node& a)const{
		return ds>a.ds;
	}
};
priority_queue<node > qu;

void  add(int u,int v,ll val){
	e[++ct].v=v;
	e[ct].val=val;
	e[ct].nxt=h[u];
	h[u]=ct;
}
ll dij(int f ,int d){
	for(int i=1;i<=n+m;i++)
		dis[i]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n+m;i++)ch[i]=false;
	dis[f]=0;
	node x;
	x.ds=dis[f],x.id=f;
	ch[f]=true;
	qu.push(x);
	while(!qu.empty()){
		int u=qu.top().id;
		ch[u]=true;		
		qu.pop();
		//printf("%d %lld\n",u,dis[u]);
		for(int i=h[u];i!=0;i=e[i].nxt){
			int v=e[i].v,val=e[i].val;
			//printf("%d %d %lld %lld \n",u,v,dis[u],dis[v]);
			if(ch[v])continue;
			if(dis[v]>dis[u]+val){
				dis[v]=dis[u]+val;
				x.ds=dis[v];
				x.id=v;
				qu.push(x);
			}
		}
	}
	
	return dis[d];		
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf ("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x; ll y;
			scanf("%d %lld",&x,&y);
			add(m+i,x,y);
			add(x,m+i,y);
		}
	}
	for(int i=1;i<=q;i++){
		int f,d;
		ll ans=0;
		scanf("%d %d",&f,&d);
		ans=dij(f,d)+w[f]+w[d];
		printf("%lld\n",ans);
	}
		
	return 0;
}
