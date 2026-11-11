#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(_,st,ed) for(int _=st;_<=ed;_++)
int c,n,m,d,Q;
const int N=1e7+1;
int w[N],k[N],id[N],station[N];
struct edge{int v,w;};
vector<edge>e[N];
void add(int u,int v,int w){
	e[u].push_back(edge{v,w});
}
int pointn;
int dis[N];
struct node{
	int w,now;
	friend bool operator<(node x,node y){
		return x.w>y.w;
	}
};
priority_queue<node>q;
void dj(int u){
	for(int i=1;i<=pointn;i++) dis[i]=1e15;
	dis[u]=0;
	q.push(node{0,u});
	while(q.size()){
		node k=q.top();
		q.pop();
		int u=k.now;
		if(dis[u]<k.w) continue;
		for(edge edg:e[u]){
			int v=edg.v,w=edg.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(node{dis[v],v});
			}
		}
	}
}
void check(){
	if(system("fc subway.out subway4.ans")){
		cout<<"WA";exit(0);
	}
	cout<<"AC";exit(0);
}
const int M=1e5+5;
struct query{
	int u,v,id;
	friend bool operator<(query x,query y){
		return x.u<y.u;
	}
}op[M];
int ans[M];
signed main(){
	//check();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	rep(i,1,m){
		id[i]=i;
		cin>>w[i];
		add(id[i],id[i]+m,w[i]);
		add(id[i]+m,id[i],w[i]);
		id[i]+=m,station[i]=id[i];
	}
	pointn=2*m;
	rep(i,1,n){
		cin>>k[i];
		int last=0;++pointn;
		rep(j,1,k[i]){
			int a,t;cin>>a>>t;
			add(pointn,station[a],t);
			add(station[a],pointn,t);
		}
	}
	rep(i,1,Q){
		cin>>op[i].u>>op[i].v,op[i].id=i;
		if(op[i].u>op[i].v) swap(op[i].u,op[i].v);
	}
	sort(op+1,op+Q+1);
	for(int i=1;i<=Q;i++){
		if(op[i].u!=op[i-1].u) dj(op[i].u);
		ans[op[i].id]=dis[op[i].v];
	}
	rep(i,1,Q) cout<<ans[i]<<"\n";
	return 0;
} 
