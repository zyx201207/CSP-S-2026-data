#include"bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
//N 线路数量 M 地铁站数量 D 地铁站度数 Q询问数量
const int N=505,M=5e5+5,D=25,Q=1e5+5;
ll dis[N][N],w[M];//线路转换时间 厅口时间
//第i个地铁所在的线路、时间 
struct node{
	int v,nxt;
	ll w;
	node(){}
	node(int v_,int nxt_,ll w_):v(v_),nxt(nxt_),w(w_){}; 
}e[M*20];//链式前向星存储 1e7条边:( 
int h[M],cnt;//表头
void add(int u,int v,ll w){//站台 线路 时间 
	e[++cnt]=node(v,h[u],w);
	h[u]=cnt;
}
int c,n,m,d,q;
void init(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	int k,v;
	ll w;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>v>>w;
			add(v,i,w);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i)
		dis[i][i]=0;
}
void addEdge(int u,int v,ll w){
	dis[u][v]=dis[v][u]=min(dis[v][u],w);
}
void buildgraph(){//建图
	for(int i=1;i<=m;++i){//枚举每个地铁站
		for(int j=h[i];j;j=e[j].nxt)//所连接的线路
			for(int k=h[i];k;k=e[k].nxt)
				if(j!=k)
				addEdge(e[j].v,e[k].v,e[j].w+e[k].w);
	}
}
void Floyd(){
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)//小=>大 对称 
			if(k!=i&&k!=j)
				addEdge(i,j,dis[i][k]+dis[k][j]);
}
void Query(){
	while(q--){
		int s,t;
		cin>>s>>t;
		ll ans=1ll<<60;
		for(int i=h[s];i;i=e[i].nxt)
			for(int j=h[t];j;j=e[j].nxt) 
				ans=min(ans,dis[e[i].v][e[j].v]+e[i].w+e[j].w);
		cout<<ans+w[s]+w[t]<<"\n";
	}
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
	init();
	buildgraph();
	Floyd();
	Query();
}

