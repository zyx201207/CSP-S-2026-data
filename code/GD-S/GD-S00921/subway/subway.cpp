#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int M=400000,N=505;
long long inf=0x3f3f3f3f;
struct ff{
	int v,w,next;
}g[M*2];
struct str{
	int u;
	long long dis;
	bool operator < (const str& b) const{
		return dis>b.dis;
	}
};
int c,n,m,dd,qq,w[M],tot,head[N+M];
long long dis[N][M+N];
bool vis[N+M];
priority_queue<str> q;
void add(int u,int v,int w){
	g[++tot]={v,w,head[u]};
	head[u]=tot;
} 
void dij(long long* d,int s){
	memset(vis,0,sizeof vis);
	d[s]=0;
	q.push({s,0});
	while(!q.empty()){
		str tmp=q.top();
		q.pop();
		int u=tmp.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=g[i].next){
			int v=g[i].v,w=g[i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({v,d[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			add(i,n+a,t);
			add(n+a,i,t);
		}
	}
	memset(dis,inf,sizeof dis);
	for(int i=1;i<=n;i++){
		dij(dis[i],i);
	}
	while(qq--){
		int s,t;
		cin>>s>>t;
		long long minn=inf;
		for(int i=1;i<=n;i++){
			minn=min(minn,dis[i][n+s]+dis[i][n+t]);
		}
		cout<<w[s]+minn+w[t]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
