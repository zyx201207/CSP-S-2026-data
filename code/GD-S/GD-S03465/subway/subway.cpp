#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
const int N=5e5+5;

int c,n,m,d,q;
int w[N],k[505];
int cur[N];//当前有几条路线
int route[N][25];//每个点的路线编号，因为不一定连续 
struct edge{
	int to,w,id;//如果有，就是路径编号
	edge(int to=0,int w=0,int id=0){
		this->to=to,this->w=w,this->id=id;
	}
};
vector<edge> g[2*N];
//g,n*0为地铁口，n*1为站厅,n*(1+k)倍为从该站厅到第k条路线的站台的花费时间
ll dis[N*20];
bool vis[N][20];

struct node{
	int id,val,time;//倍数 
	friend bool operator < (node a,node b){
		return a.val>b.val;
	}
	node(int id=0,int val=0,int time=0){
		this->id=id,this->val=val,this->time=time;
	}
};
void dijkstra(int s){
	for(int i=1;i<20*N;i++){
		dis[i]=1e9;
	}
	memset(vis,0,sizeof vis);
	priority_queue<node> Q;
	Q.push(node(s,0,0));
	dis[s]=0;
	while(!Q.empty()){
		int u=Q.top().id,t=Q.top().time;//始终保持u是地铁站编号，用倍数维护当前位置 
		Q.pop();
		if(vis[u][t]) continue;
//		cout<<u<<' '<<t<<' '<<dis[u+t*m]<<'\n';
		vis[u][t]=1;
		if(t==0){//在地铁口 
			for(edge E:g[u]){
				int v=E.to,w=E.w;
				if(v==u+m){//去站厅 
					if(dis[v]>dis[u]+w){
						dis[v]=dis[u]+w;
						Q.push(node(u,dis[v],1));//进入站厅时带的是原地铁站编号 
					}
				}
			}
		}
		else if(t==1){//在站厅 
			for(int i=1;i<=cur[u];i++){//去站台 
				int id=route[u][i];
				if(dis[u+m*(1+i)]>dis[u+m]+w[u]){
					dis[u+m*((i+1))]=dis[u+m]+w[u];
					Q.push(node(u,dis[u+m*(1+i)],i+1));
				}
			}
			for(edge E:g[u+m]){//去地铁口 
				int v=E.to,w=E.w;
				if(v==u){
					if(dis[v]>dis[u+m]+w){
						dis[v]=dis[u+m]+w;
						Q.push(node(v,dis[v],0));
					}
				}
			}
		}
		else {//在某个站台 
			for(edge E:g[u+m*t]){
				int v=E.to,w=E.w;
				if(m+1<=v&&v<=2*m){//去站厅
					if(dis[v]>dis[u+m*t]+w){
						dis[v]=dis[u+m*t]+w;
						Q.push(node(v-m,dis[v],1));//进入站厅时带的是原地铁站编号
					}
				}
				else {//去另一个站台
//					cout<<u+m*t<<' '<<v<<'\n';
					if(dis[v]>dis[u+m*t]+w){
						dis[v]=dis[u+m*t]+w;
						int cnt=0;//判断是对于v是第几条路线 
						while(v>m){
							++cnt;
							v-=m;
						}
						if(v==0){
							v=m,--cnt;
						}
//						cout<<"对于"<<v<<"是第"<<cnt-1<<"条路线"<<'\n';
						Q.push(node(v,dis[v],cnt));
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i].pb(edge(i+m,w[i],0));
		g[i+m].pb(edge(i,w[i],0));
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a,aa=0,t,tt=0;
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			++cur[a];
			route[a][cur[a]]=i;
			g[a+m].pb(edge(a+m*(1+cur[a]),t,i));
			g[a+m*(1+cur[a])].pb(edge(a+m,t,i));
			if(j>1){
				g[a+m*(1+cur[a])].pb(edge(aa+m*(1+cur[aa]),0,i));
				g[aa+m*(1+cur[aa])].pb(edge(a+m*(1+cur[a]),0,i));
//				cout<<a+m*(1+cur[a])<<' '<<aa+m*(1+cur[a])<<'\n';
			}
			aa=a,tt=t;
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		dijkstra(s);
		cout<<dis[e]<<'\n';
	}
//	for(int i=1+2*m;i<=3*m;i++){
//		cout<<i<<'\n';
//		for(edge E:g[i]){
//			cout<<E.to<<' '<<E.w<<'\n';
//		}
//	}
	return 0;
}
