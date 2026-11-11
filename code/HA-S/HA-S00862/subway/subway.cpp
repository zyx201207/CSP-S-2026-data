#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int c,n,m,d,q,cnt,head[600006];
ll w[500005],dis[501505];
bool vis[500005];
int read(){
	int f=1,res=0;
	char z=getchar();
	while(z=='-')f=-1,z=getchar();
	while(z>='0'&&z<='9'){
		res=res*10+z-'0';
		z=getchar();
	}
	return res*f;
}
ll out(ll ans){
	if(ans==0){
		putchar('0\n');
	}
	while(ans!=0){
		putchar(ans%10+'0');
		ans/=10;
	}
	putchar('\n');
}
struct no{
	int to,nxt;
	ll w;
}e[1000005];
void add(int u,int v,ll w){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void dijkstra(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=500505;i++)dis[i]=inf;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;		
		ll diss=pq.top().first;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>diss+e[i].w){
				dis[v]=diss+e[i].w;
				pq.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//c=read();n=read();m=read();d=read();q=read();
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		//k=read();
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int v;ll w;
			//v=read();w=read();
			scanf("%d%lld",&v,&w);
			add(m+i,v,w);add(v,m+i,w);
		}
	}
	while(q--){
		int s,end;
		//s=read();end=read();
		scanf("%d%d",&s,&end);
		dijkstra(s);
		//out(dis[end]+w[s]+w[end]);
		printf("%lld\n",dis[end]+w[s]+w[end]);
	}
	return 0;
}
