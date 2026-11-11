#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,int> pii;

const int N=505,M=2e4+5,D=25,Q=1e5+5;
const ll INF=1e18;

int sub,n,m,d,q,cur,head[M*D],ent[M],bel[M*D],idk,line[M*D],nop[M],t[M*D],vis[M*D];
ll ans[Q],dis[D][M*D];
vector<int> g[M];
struct edge{int to,next;ll val;}e[D*D*M+M*2];
struct query{int x,y,id;}qry[Q];

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void add(int u,int v,int w){e[++cur]={v,head[u],w};head[u]=cur;}

void dijkstra(int st,int id){
	for(int i=1;i<=idk;++i)dis[id][i]=INF,vis[i]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,st});dis[id][st]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[id][u]+e[i].val<dis[id][v]){dis[id][v]=e[i].val+dis[id][u];q.push({dis[id][v],v});}
		} 
	}
}

bool cmp(query xx,query yy){
	return xx.x<yy.x;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	sub=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i)ent[i]=read();
	
	for(int i=1;i<=n;++i){
		int station=read();for(int j=1,aa,lst,tt;j<=station;++j){
			aa=read(),tt=read();bel[++idk]=aa;line[idk]=i,t[idk]=tt;
			if(nop[aa])for(int k=0;k<g[aa].size();++k){
//				printf("--------------%d %d %d\n",aa,g[aa][k],idk);
				
				add(g[aa][k],idk,t[idk]+t[g[aa][k]]),add(idk,g[aa][k],t[idk]+t[g[aa][k]]);
			}
			g[aa].push_back(idk);nop[aa]=1;
			if(j!=1)add(lst,idk,0),add(idk,lst,0);
			lst=idk;
		}
	}
	
	for(int i=1;i<=q;++i){qry[i]={read(),read(),i};ans[i]=INF;}
	sort(qry+1,qry+1+q,cmp);
	
	
	for(int i=1,lst=0;i<=q;){
		if(qry[i].x!=lst){
			for(int j=0;j<g[qry[i].x].size();++j){dijkstra(g[qry[i].x][j],j);}lst=qry[i].x;
		}
		while(qry[i].x==lst&&i<=q){
			for(int j=0;j<g[qry[i].x].size();++j){
				for(int k=0;k<g[qry[i].y].size();++k){
//					printf("xj=%d ; yk=%d ; i=%d\n ;j=%d\n ;k=%d\n",g[qry[i].x][j],g[qry[i].y][k],i,j,k);
//					printf("dis-xj-to-yk=%d\n",dis[j][g[qry[i].y][k]]);
					ans[qry[i].id]=min(ans[qry[i].id],dis[j][g[qry[i].y][k]]+t[g[qry[i].x][j]]+t[g[qry[i].y][k]]+ent[qry[i].x]+ent[qry[i].y]);
				}
			}
			++i;
		}
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}

// M!!!!
