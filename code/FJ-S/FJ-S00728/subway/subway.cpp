#include<bits/stdc++.h>
#define N 500005
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int c,n,m,d,Q;
int w[500005];
struct Edge{
	int v,w;
};
vector<Edge>edge[N*3];
void add(int u,int v,int w){
	edge[u].push_back({v,w});
}
struct XY{
	int x,y;
};
vector<XY>a[N];
struct Node{
	int u,dis;
	bool operator>(const Node& a)const{
		return dis>a.dis;
	}
};
priority_queue< Node,vector<Node>,greater<Node> >q;
int dis[N*3];
bool vis[N*3];
void dij(int s){
	for(int i=1;i<=2*m+n;i++)dis[i]=0x3f3f3f3f;
	for(int i=1;i<=2*m+n;i++)vis[i]=0;
	while(!q.empty())q.pop();
	dis[s]=0;
	q.push({s,dis[s]});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(Edge e:edge[u]){
			int v=e.v,w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int ans[100005];
int Final[500005];
vector<XY>Op[100005];
bool jud[500005];
vector<int>g[N];
namespace Sub{
	struct node{
		int u,t;
	};
	queue<node>q;
	bool vis[N];
	int bfs(int s,int tt){
		while(!q.empty())q.pop();
		q.push({s,0});
		memset(vis,0,sizeof(vis));
		while(!q.empty()){
			int u=q.front().u,t=q.front().t;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int v:g[u]){
				if(v==tt)return t+1;
				q.push({v,t+1});
			}
		}
	}
}
int PP=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		add(i,i+m,w[i]),add(i+m,i,w[i]);
	}
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int ed=read(),t=read();
			a[i].push_back({ed,t});
			add(i+2*m,ed+m,t),add(ed+m,i+2*m,t);
			g[i+m].push_back(ed),g[ed].push_back(i+m);
			PP=t;
		}
	}
	int cnt=0;
	if(c==0||12<=c&&c<=19){
		while(Q--){
			int u=read(),v=read();
			cout<<PP*Sub::bfs(u,v)+w[u]+w[v]<<"\n";
		}
	}
	else{
		for(int i=1;i<=Q;i++){
			int u=read(),v=read();
			if(!jud[u]){
				jud[u]=1;
				Final[++cnt]=u;
			}
			Op[u].push_back({i,v});
		}
		sort(Final+1,Final+cnt+1);
		for(int i=1;i<=cnt;i++){
			int now=Final[i];
			int len=Op[now].size();
			dij(now);
			for(int j=0;j<len;j++){
				ans[Op[now][j].x]=dis[Op[now][j].y];
			}
		}
		for(int i=1;i<=Q;i++){
			cout<<ans[i]<<"\n";
		}
	}
	
	return 0;
}

