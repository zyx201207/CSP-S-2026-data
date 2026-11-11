#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define int long long
#define F(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define f(x,y) for(auto x:y)
#define lt(x) x&-x
#define d2(l,r) (l+r>>1)
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
const int N=5e5+15,Q=1e5+15;
int rubbish,n,m,D,q;
int cnt[N];
struct edge{
	int v,w;
};
vector<edge> g[N*25];
struct nodeq{
	int id,d;
	bool operator <(const nodeq &o)const{return d>o.d;}
};
int d[N*25],vis[N*25];
void Dijkstra(int s){
	memset(d,127,sizeof(d));
	memset(vis,0,sizeof vis);
	d[s]=0;
	priority_queue<nodeq> q;
	q.push((nodeq){s,d[s]});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		f(x,g[u]){
			int v=x.v,w=x.w;
			if(vis[v]) continue;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
//				cout<<v<<' '<<d[v]<<endl;
				q.push((nodeq){v,d[v]});
			}
		}
	} 
}
struct node{
	int y,id;
};
vector<node> qy[N];
set<int> st;
int ans[Q];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>rubbish>>n>>m>>D>>q;
	F(i,1,m){
		int w;
		cin>>w; 
		g[i+(D+1)*m].push_back((edge){i,w});
		g[i].push_back((edge){i+(D+1)*m,w});
	}
	F(i,1,n){
		int k;
		cin>>k;
		int u,t;
		cin>>u>>t;
		cnt[u]++;
		g[u].push_back((edge){u+cnt[u]*m,t});
		g[u+cnt[u]*m].push_back((edge){u,t});
		F(j,2,k){
			int v;
			cin>>v>>t;
			cnt[v]++;
			g[v].push_back((edge){v+cnt[v]*m,t});
			g[v+cnt[v]*m].push_back((edge){v,t});
			g[u+cnt[u]*m].push_back((edge){v+cnt[v]*m,0});
			g[v+cnt[v]*m].push_back((edge){u+cnt[u]*m,0});
			u=v;
		}
	}
	F(i,1,q){
		int x,y;
		cin>>x>>y;
//		Dijkstra(x+(D+1)*m);
		if(x>y) swap(x,y);
		st.insert(x);
		qy[x].push_back((node){y,i});
//		cout<<d[y+(D+1)*m]<<endl;
	}
	f(x,st){
		Dijkstra(x+(D+1)*m);
		f(z,qy[x]){
			int y=z.y,id=z.id;
			ans[id]=d[y+(D+1)*m];
		}
	}
	F(i,1,q) cout<<ans[i]<<endl;
}
