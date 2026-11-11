#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+5,N=505;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M],k[N],t[M][N];
vector<int> sta[M];
ll dis[M];
struct Edge{
	int to,id;
	Edge(int v,int i):to(v),id(i){}
};
struct Info{
	int cur,id;
	ll dis;
	bool operator<(const Info&oth)const{
		return dis<oth.dis;
	}
	Info(int a,int i,ll d):cur(a),id(i),dis(d){
	}

bool operator>(const Info&oth)const{
	return dis>oth.dis;}
	};
vector<Edge>adj[M];
//bool vis[M];
inline ll bfs(int s,int et){
	priority_queue<Info,vector<Info>,greater<Info> >q;
	for(int i=1;i<=n;i++) dis[i]=INFLL;
	for(int f:sta[s])
		q.emplace(s,f,t[s][f]),dis[s]=min(dis[s],1LL*t[s][f]);
	while(!q.empty()){
		Info tmp=q.top();q.pop();
		int u=tmp.cur,id=tmp.id;
		ll d=tmp.dis;
		if(d>dis[u])continue;
		for(Edge x:adj[u]){
			int v=x.to,nxtid=x.id;
			if(id==nxtid){
				if(v==et&&dis[et]>d+t[et][id]){
					dis[et]=d+t[et][id];
				}else if(dis[v]>d){
					dis[v]=d;
					q.emplace(v,id,d);
				}
			}
			else{
				if(v==et&&dis[et]>d+t[u][id]+t[u][nxtid]+t[et][nxtid]){
					dis[et]=d+t[u][id]+t[u][nxtid]+t[et][nxtid];
				}else if(dis[v]>d+t[u][id]+t[u][nxtid]){
					dis[v]=d+t[u][id]+t[u][nxtid];
					q.emplace(v,nxtid,dis[v]);
				}
			} 
		}
	}
	return dis[et];
}/*
0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int lst=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,spt;
			cin>>u>>spt;
			sta[u].emplace_back(i);
			t[u][i]=spt;
			if(lst){
				adj[lst].emplace_back(u,i);
				adj[u].emplace_back(lst,i);
			}
			lst=u;
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+bfs(u,v)<<'\n';
	}
	return 0;
}
