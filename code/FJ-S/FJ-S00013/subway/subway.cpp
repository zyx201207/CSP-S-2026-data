#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=510,M=5e5+10;
const int MAXN=M*2+N;
const ll INF=1e17;
int c,n,m,d,q,idx,timer;
int W[N],K[N],dfn[MAXN];
ll sum[MAXN];
int maxn=0;
map<pair<int,int>,int > mp,T;//Ó³Éä½Úµã±àºÅ 

struct node{
	int v;
	ll w;
	bool operator<(const node &a)const{
		return w>a.w;
	}
};

vector<node> e[MAXN];
int st[21][MAXN];

void add_edge(int u,int v,int w){
//	printf("%d--%d w:%d\n",u,v,w);
	e[u].push_back(node{v,w});
	e[v].push_back(node{u,w});
}

void dfs(int x,int fa){
	st[0][dfn[x]=++timer]=fa;
//	printf("v:%d\n",x);
	for(auto G:e[x]){
		int y=G.v,w=G.w;
		if(y==fa)continue;
		sum[y]=sum[x]+w;
		dfs(y,x);
	}
}

int get(int x,int y){
	if(dfn[x]<dfn[y])return x;
	return y;
} 

void init_lca(){
	for(int j=1;(1<<j)<=maxn;++j){
		for(int i=1;i+(1<<j)-1<=maxn;++i){
			st[j][i]=get(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	} 
}

int lca(int x,int y){
	if(x==y)return x;
	if(dfn[x]+1>dfn[y])swap(x,y);
	int l=dfn[x]+1,r=dfn[y];
	int k=__lg(r-l+1);
	return get(st[k][l],st[k][r-(1<<k)+1]);
}

ll path_sum(int x,int y){
	return sum[x]+sum[y]-2*sum[lca(x,y)];
} 

namespace subtask1{
	const int V=510;
	ll f[V][V];
	void solve(){
		rep(i,1,maxn){
			rep(j,1,maxn){
				f[i][j]=INF;
			} 
		}
		rep(i,1,maxn){
			f[i][i]=0;
		}
		for(int i=1;i<=maxn;++i){
			for(auto G:e[i]){
				int j=G.v,w=G.w;
				f[i][j]=w;
			}
		}
		rep(k,1,maxn){
			rep(i,1,maxn){
				rep(j,1,maxn){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			} 
		}
		rep(_,1,q){
			int u,v;
			scanf("%d %d",&u,&v);
			printf("%lld\n",f[u][v]);
		}
	}
}

namespace subtask2{
	const int V=4010;
	ll dis[V];
	ll res[V][V];
	bool vis[V];
	void dijkstra(int S){
		rep(i,1,maxn){
			dis[i]=INF;
			vis[i]=0;
		}
		priority_queue<node> q;
		dis[S]=0;
		q.push(node{S,0});
		while(!q.empty()){
			int x=q.top().v;
			q.pop();
			if(vis[x])continue;
			vis[x]=1;
			for(auto G:e[x]){
				int y=G.v,w=G.w;
				if(dis[y]>dis[x]+w){
					dis[y]=dis[x]+w;
					q.push(node{y,dis[y]});
				}
			}
		}
		rep(i,1,maxn){
			res[S][i]=dis[i];
		}
	} 
	void solve(){
		rep(i,1,maxn){
			dijkstra(i);
		}
		rep(_,1,q){
			int u,v;
			scanf("%d %d",&u,&v);
			printf("%lld\n",res[u][v]);
		} 
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	idx=m*2;
	rep(i,1,m){
		scanf("%d",&W[i]);
	}
	rep(i,1,n){
		scanf("%d",&K[i]);
		int lst=0;
		for(int j=1;j<=K[i];++j){
			int a,t;
			scanf("%d %d",&a,&t);
			mp[{i,a}]=++idx;
//			T[{i,a}]=t;
			if(j>=2){
				add_edge(mp[{i,lst}],mp[{i,a}],0); 
//				add_edge(mp[{i,a}],mp[{i,lst}],0); 
			}
			add_edge(mp[{i,a}],a+m,t);//Õ¾Ì¨¡¢Õ¾Ìü
//			add_edge(a+m,mp[{i,a}],t);
			lst=a;
		} 
	} 
	for(int i=1;i<=m;++i){
		add_edge(i,i+m,W[i]);//µØÌú¿Ú->Õ¾Ìü
//		add_edge(i+m,i,W[i]); 
	}
	maxn=idx;
	if(maxn<=500){
		subtask1::solve();
		return 0;
	}else if(maxn<=5000){
		subtask2::solve();
		return 0;
	}
	return 0;
}

