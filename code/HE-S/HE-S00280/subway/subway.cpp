#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x){
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int c,n,m,d,q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int ww[M];
struct Edge{
	int w,v;
};
vector<Edge> edge[M];
int dis[M];
bool vis[M];
void xa(){
	for(int i=1;i<=n;i++){
		int k=read();
		int x=read(),y=read();
		int tx=read(),ty=read();
		int w=tx+ty;
		edge[x].push_back({(tx+ty),y}); 
		edge[y].push_back({(tx+ty),x}); 
	}
	while(q--){
		int x=read(),y=read();
		memset(dis,0x3f3f3f3f,(m+1)*sizeof(int));
		memset(vis,0,(m+1)*sizeof(int));
		queue<int> q;
		q.push(x);
		dis[x]=0;
		vis[x]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto e:edge[u]){
				int v=e.v;
				int w=e.w;
				if(vis[v]) continue;
				if(dis[v]>dis[u]+w){
					vis[v]=1;
					dis[v]=dis[u]+w;
					q.push(v);
				}
			}
		}
		write(dis[y]+ww[x]+ww[y]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		ww[i]=read();
	}
	xa();
}
