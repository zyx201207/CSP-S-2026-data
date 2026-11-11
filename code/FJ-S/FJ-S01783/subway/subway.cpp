#include<bits/stdc++.h>
using namespace std;
const int M=50505;
inline int read(){
	int f=1,x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	return f*x;
}
struct edge{
	int v,w;
};
struct point{
	int u,w;
	bool operator <(const point x) const {
		return w<x.w;
	} 
};
struct query{
	int id,x,y,t;
}ans[100005];
int n,m,c,d,q;
vector<edge> e[M];
bool vis[M];
int dis[M];
void dijkstra(int a){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<point> q;
	q.push((point){a,0});
	dis[a]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		int l=e[u].size();
		for(int i=0;i<l;i++){
			edge o=e[u][i];
			if(vis[o.v])continue; 
			if(dis[o.v]>dis[u]+o.w){
				dis[o.v]=dis[u]+o.w;
				q.push((point){o.v,-dis[o.v]});
			}
		}
	}
}
int w[M];
bool cmp1(query a,query b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
bool cmp2(query a,query b){
	return a.id<b.id;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=m+1;i<=n+m;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			e[i].push_back((edge){a,t});
			e[a].push_back((edge){i,t});
		}
	}
	for(int i=1;i<=q;i++){
		ans[i].id=i;
		ans[i].x=read();
		ans[i].y=read();
	}
	sort(ans+1,ans+q+1,cmp1);
	for(int i=1;i<=q;i++){
		if(ans[i].x!=ans[i-1].x){
			dijkstra(ans[i].x);
		}
		ans[i].t=w[ans[i].x]+w[ans[i].y]+dis[ans[i].y];
	}
	sort(ans+1,ans+q+1,cmp2);
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i].t);
	}
	for(int i=1;i<=m;i++)
	fclose(stdin);fclose(stdout);
	return 0;
} 
