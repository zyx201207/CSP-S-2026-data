#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define pi pair<int,int>
using namespace std;
const int N=1e5+10,M=510,inf=1e9+7;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int c,n,m,d,Q;
int w[N];
struct edge{
	int from,to,val,nxt;
}e[N*200];
int h[N*100],tot;
void add(int u,int v,int w){
	e[++tot].from=u;
	e[tot].to=v;
	e[tot].val=w;
	e[tot].nxt=h[u];
	h[u]=tot;
	return;
}
int ti[M][N];
int cnt;
int get(int i,int j){
	//第i条线路的点j 
	return (j-1)*d+i;
}
priority_queue<pi> q;
int dis[N*100];
bool vis[N*100];
void init(){
	for(int i=1;i<=cnt;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	while(q.size()) q.pop();
	return;
}
void dijkstra(int s){
	s=n*d+s;
	dis[s]=0;
	q.push(mk(0,s));
	int u,v,w;
	while(q.size()){
		u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			v=e[i].to;w=e[i].val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(mk(-dis[v],v));
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();m=read();n=read();d=read();Q=read();
	for(int i=1;i<=n;i++) w[i]=read();
	//每个点都建立d个点
	cnt=d*n;
	int k,u,v,t;
	for(int i=1;i<=m;i++){
		//第i条路线 
		k=read();
		for(int j=1;j<=k;j++){
			t=read();
			if(j==1) u=get(i,t);
			else{
				v=get(i,t);
				add(u,v,0);add(v,u,0);
				u=v;
			}
			ti[i][t]=read();
		}
	}
	for(int i=1;i<=n;i++){
		cnt++;
		//点i
		for(int j=1;j<=d;j++){
			//线路j 
			u=get(j,i);
			t=ti[j][i];
			add(u,cnt,t);add(cnt,u,t);
		}
	}
	int ans;
	while(Q--){
		scanf("%d%d",&u,&v);
		init();
		dijkstra(u);
		ans=dis[n*d+v]+w[u]+w[v];
		printf("%d\n",ans);
	}
	return 0;
}
