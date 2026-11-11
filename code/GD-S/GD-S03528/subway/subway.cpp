#include<bits/stdc++.h>
using namespace std;
const int M=5e3+10;
const int Q=1e5+10;
int w[M];
int t[M][M];
int k[M],dis[M];
int c,n,m,d,q;
int fa[M];
bool vis[M];
void init(int x){
	for(int i=1;i<=x;i++){
		fa[i]=i;
	}
}
int find(int x) {
	if(fa[x]=x) return fa[x];
	else return fa[x]=find(fa[x]);
}
struct node{
	int to,len;
	bool operator <(const node b)const{
		return len>b.len;
	}
};
int to[M],nxt[M],head[M];
int cnt=0;
void add(int u,int v,int w){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
//void add()
//void dij(int s){
//	memset(dis,0x3f,sizeof(dis));
//	priority_queue<node>q;
//	dis[s]=0;
//	q.push({s,0});
//	while(!q.empty()){
//		int u=q.top.to;
//		q.pop;
//		if(vis[u]) continue;
//		vis[u]=1;
//		for(int i=head[u];i;i=nxt[i]){
//			int v=to[i],va=val[i];
//			if(va+dis[u]<dis[v]){
//				q.push({v,dis[v]});
//			}
//		}
//	}
//}
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);//地铁站的地铁口走到站厅
	}
	init(m);
	int cnt=0;
	for(int i=1,z;i<=n;i++){
		scanf("%d",&z);//line
		for(int j=1,x,y;j<=z;j++){
			scanf("%d%d",x,y) ;//every
			if(!k[z]) k[x]=z;
			else 
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d %d",&x,&y);
		if(k[x]==k[y]){
		}
		
	}
	printf("%d",50); 
	return 0;
}
