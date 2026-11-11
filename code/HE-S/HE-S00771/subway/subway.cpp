#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define pii pair<int,int> 
#define mpi make_pair
#define fi first
#define se second
typedef long long ll;
namespace IO{
	#define CH getchar
	template <typename T>
	inline T read(){
		T f=1,x=0;
		char c=CH();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=CH();}
		while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=CH();
		return f*x;
	}
	#define PUT putchar
	template <typename T>
	inline void write(T x){
		if(x==0){PUT('0');return;}
		if(x<0){PUT('-');x=-x;}
		int sta[40],top=0;
		while(x)sta[top++]=x%10,x/=10;
		while(top)PUT(sta[--top]+'0');
	}
	template <typename T>
	inline void print(T x){write(x);PUT('\n');}
}
using namespace std;
using namespace IO;
const int N=5e2+5;
const int M=5e5+5;
const int Dij=1e3+5;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,C,d,Q;
int w[M],k[N];
pii op[M];
ll f[N][N];
struct node{
	int v;ll w;
	bool operator <(const node&rhs)const{return w>rhs.w;}
};
vector<node>adj[N];
vector<int>edg[N],dt[M];
vector<ll>z[M];
ll dis[Dij][Dij];
bool vis[Dij];
void dijkstra(int s,ll *dist){
	priority_queue<node>pq;
	for(int i=1;i<=m;i++)vis[i]=0,dist[i]=inf;
	pq.push({s,0});dist[s]=0;
	while(!pq.empty()){
		node cur=pq.top();pq.pop();
		if(vis[cur.v])continue;
		vis[cur.v]=1;
		for(node now:adj[cur.v]){
			if(dist[now.v]>dist[cur.v]+now.w)
				dist[now.v]=dist[cur.v]+now.w,
				pq.push({now.v,dist[now.v]});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read<int>(),n=read<int>(),m=read<int>(),d=read<int>(),Q=read<int>();
	for(int i=1;i<=m;i++)w[i]=read<int>();
	for(int i=1;i<=n;i++){
		k[i]=read<int>();
		for(int j=1,c,di;j<=k[i];j++)
			c=read<int>(),di=read<int>(),
			edg[i].push_back(c),
			z[c].push_back(di),dt[c].push_back(i);
	}      
	for(int i=1,x,y;i<=Q;i++)x=read<int>(),y=read<int>(),op[i]=mpi(x,y);
//	if(C>=7&&C<=11){
//		for(int i=1;i<=n;i++){
//			int fr=edg[i][0],to=edg[i][1];
//			adj[fr].push_back({to,z[fr][i]+z[to][i]});
//			adj[to].push_back({fr,z[fr][i]+z[to][i]});
//		}
//		for(int i=1;i<=m;i++)dijkstra(i,dis[i]);
//		for(int i=1;i<=Q;i++)print<ll>(dis[op[i].fi][op[i].se]+w[op[i].fi]+w[op[i].se]);
//		return 0;
//	}//sp A 7-11 20pts 16:00
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int k=0;k<(int)dt[i].size();k++){
			for(int j=0;j<(int)dt[i].size();j++){
				if(k==j)continue;
				f[dt[i][k]][dt[i][j]]=f[dt[i][j]][dt[i][k]]=min(z[i][j]+z[i][k],f[dt[i][k]][dt[i][j]]);
			}
		}}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=Q;i++){
		int x=op[i].fi,y=op[i].se;
		ll ret=INF;
		for(int k=0;k<(int)dt[x].size();k++)
			for(int j=0;j<(int)dt[y].size();j++){
				ret=min(ret,f[dt[x][k]][dt[y][j]]+z[x][k]+z[y][j]);
			}
		print<ll>(ret+w[x]+w[y]);
	}                                                                                                                                                                                    
	return 0;
}
//end 18:10 
