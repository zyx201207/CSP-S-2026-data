#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=505,M=5e5+5,inf=0x3f3f3f3f3f3f3f3fll;
int c,n,m,D,_;
int w[M];
vector<pair<int,int> > d[M];
struct edge{
	int v,c,next;
} e[N*N<<1];
int h[N],ecnt=0;
int weight[N][N],dis[N][N];
void addedge(int u,int v,int c){
	e[++ecnt]={v,c,h[u]},h[u]=ecnt;
}
struct dat{
	int dis,u;
	bool operator>(const dat &x)const{
		if(dis==x.dis) return u<x.u;
		return dis<x.dis;
	}
};
priority_queue<dat,vector<dat>,greater<dat> > q;
bool vis[N];
void dijkstra(int s){
	rep(i,1,n) dis[s][i]=inf;
	rep(i,1,n) vis[i]=0;
	while(!q.empty()) q.pop();
	dis[s][s]=0,q.push({0,s});
	while(!q.empty()){
		dat now=q.top();
		q.pop();
		int u=now.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].next){
			int v=e[i].v,c=e[i].c;
			if(dis[s][v]>dis[s][u]+c){
				dis[s][v]=dis[s][u]+c;
				q.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	// start coding at 15:17
	// finish coding and accepted at the first time running at 15:37
	// today is the day.
	c=read(),n=read(),m=read(),D=read(),_=read();
	rep(i,1,m) w[i]=read();
	rep(i,1,n){
		int k=read();
		rep(j,1,k){
			int v=read(),x=read();
			d[v].push_back({i,x});
		}
	}
	// build graph
	memset(weight,0x3f,sizeof(weight));
	rep(i,1,n) weight[i][i]=0;
	rep(i,1,m){
		for(auto x:d[i]){
			int u=x.first;
			for(auto y:d[i]){
				int v=y.first;
				weight[u][v]=min(x.second+y.second,weight[u][v]);
				weight[v][u]=min(x.second+y.second,weight[v][u]);
			}
		}
	}
	rep(i,1,n){
		rep(j,i+1,n){
			addedge(i,j,weight[i][j]);
			addedge(j,i,weight[i][j]);
		}
	}
	rep(i,1,n){
		dijkstra(i);
	}
	while(_--){
		int x=read(),y=read();
		int ans=w[x]+w[y],mn=inf;
		for(auto xx:d[x]){
			for(auto yy:d[y]){
				int res=xx.second+yy.second+dis[xx.first][yy.first];
				mn=min(mn,res);
			}
		}
		ans+=mn;
		printf("%lld\n",ans);
	}
	return 0;
}