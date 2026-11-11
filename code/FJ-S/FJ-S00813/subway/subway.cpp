#include <iostream>
#include <queue>
#include <cstring>

#define gc getchar()
#define ll long long 
using namespace std;
const int MAXM=5e5+114; // 地铁节点数 
const int MAXN=514; // 线路节点数 
//const int MAXK=5e5+114; //也许可以去除：单条线路最大连接节点数 
const int MAXD=22;
inline ll read(){
	ll p=0,k=1;
	char c=gc;
	while (c<'0'||c>'9') {
		if (c=='-') k=-k;
		c=gc;
	}
	while (c>='0'&&c<='9') p=p*10+c-'0',c=gc;
	return p*k;
}
int c,n,m,d,Q;
ll w[MAXM];

ll p[MAXM][MAXD]; 
ll enter[MAXN][MAXM]; //ll?
bool cat[MAXN][MAXN];
ll exc[MAXN][MAXN] ; //ll?
// p[i][j]表示i号点 拥有的第j号路线 
// p[i][0]存储这个点被几条地铁线路穿过

//enter[i][j] j号点进入i线路的开销 

// exc[i][j] 存储第i条线路到第j条线路的最小换乘费用  
// 特别地，exc[i][i]=0
// 需要后维护
// 先将线路到线路的换乘抽象为图，尝试找出边权跑dijikstra 

ll total[MAXN][MAXN];
void init(){
	//初始化在这里完成 
	for (int i=0;i<MAXN;i++)
		for (int j=0;j<MAXN;j++) {
			if(i==j) exc[i][j]=0,total[i][j]=0;
			else exc[i][j]=1e16,total[i][j]=1e16; 
		}
} 

//建图环节 
int cnt=0,nxt[MAXM],to[MAXM],head[MAXN];
void edge(int u,int v){
	cnt++;
	nxt[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v; 
}// 记得开双向 ,也许不需要更新val 

struct node{
	int id;
	ll cost;
};
bool operator> (const node& a,const node& b){
	return a.cost>b.cost;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),Q=read();
	
	for (int i=1;i<=m;i++) w[i]=read(); //固定开销 
	init() ;
	
	for (int i=1;i<=n;i++){
		int k=read();
		for (int j=1;j<=k;j++) {//read a,t
			int a=read(),t=read();
			enter[i][a] =t; // 从点a进入i路线的开销就是t 
			for (int k=1;k<=p[a][0];k++) {
				exc[p[a][k]][i] =min(exc[p[a][k]][i],enter[p[a][k]][a]+enter[i][a]) ; 
				exc[i][p[a][k]] =exc[p[a][k]][i];
				// 更新直接连接的点间的最小边权  ,双向 
				cat[p[a][k]][i] =true;
				cat[i][p[a][k]] =true; 
				//标记这两点间有边，双向 
			}
			p[a][0]++,p[a][p[a][0]]=i; //将这条路线加入点中 
			
		}
	}
	//建图 
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) { //自动双向 
			if(cat[i][j]) //如果i j有边 
				edge(i,j);
		}
	} 
	
	priority_queue<node,vector<node> ,greater<node> > q; 
	for (int i=1;i<=n;i++){//遍历起点跑dj 
		while(!q.empty()) q.pop(); //先清空,也许不需要 
		bool ok[MAXN];//点是否更新过 
		memset(ok,false,sizeof(ok)); //初始化 
		//for (int I=1;I<MAXN;I++) ok[i]=false;
		q.push({i,0}); //加入起点 
		while (!q.empty()) {
			while (!q.empty()&&ok[q.top().id]) q.pop();
			
			if(!q.empty()){
				int u=q.top().id;
				int e=head[u];
	
				while(e!=0) {
					int v=to[e];
					if(ok[v]) {
						e=nxt[e];
						continue;
					}
					total[i][v]=min(total[i][v],total[i][u]+exc[u][v]);
					total[i][v]=min(total[v][i],total[i][v]);
					//total[v][i]=total[i][v];
					q.push({v,total[i][v]});
					e=nxt[e];
				}
				
				ok[u]=true;
				q.pop();
			}
			//ok[q.top().id] 
		}
	} 
	
	//处理询问
	while(Q--){
		int x=read(),y=read();
		ll ans=1e16;
		for (int i=1;i<=p[x][0];i++){
			for (int j=1;j<=p[y][0];j++){
				ans=min(ans,
						w[x]
						+w[y]
						+enter[p[x][i]][x]
						+enter[p[y][j]][y]
						+total[p[x][i]][p[y][j]] );
				// 进入x开销 +进入y开销+ 进入i路线开销+进入j路线开销+ ij换乘开销 
			}
		}
		printf("%lld\n",ans); 
	} 
	
	return 0;
} 


