#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=1e5+10;
const int Q=1e5+5;
const int INF=1e18;
typedef struct Node{
	int now,dis;
	bool operator()(const Node &A,const Node&B){
		return A.dis>B.dis;
	};
}Node;
typedef struct Que{
	int x,y,id;
}Que;
Que qs[Q];
int id,n,m,d,q,as[N];
int w[M];
int cnt[N];
int t[N][M];
int a[N][M];
int ans=LLONG_MAX;
int dist[N];
bool vis[N];
vector<pair<int,int> > had[M];
priority_queue<Node,vector<Node>,Node> que;
inline bool cmp(const Que &A,const Que &B){
	return A.x<B.x;
}
inline void dij(int x){
	Node item;
	item.now=x;
	item.dis=0;
	que.push(item);
	while(que.size()){
		Node tp=que.top();
		que.pop();
		int u=tp.now;
		if(vis[u])continue;
		vis[u]=true;
		for(auto it:had[u]){
			int idx=it.first;
			int wai=it.second;
			for(int i=1;i<=cnt[i];++i){
				int v=a[idx][i];
				int part=tp.dis+wai+t[idx][i];
				if(part<=dist[v]){
					dist[v]=part;
					item.now=v;
					item.dis=part;
					que.push(item);
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&id,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&cnt[i]);
		for(int j=1;j<=cnt[i];++j){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
			had[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}
	for(int i=1;i<=q;++i){
		scanf("%lld %lld",&qs[i].x,&qs[i].y);
		qs[i].id=i;
	}
	sort(qs+1,qs+1+q,cmp);
	int lst=0;
	for(int i=1;i<=q;++i){
		int x,y;
		x=qs[i].x;
		y=qs[i].y;
		if(x!=lst){
			fill(dist+1,dist+1+m,INF);
			dist[x]=0;
			fill(vis+1,vis+1+m,false);
			dij(x);
		}
		int ans=dist[y]+w[x]+w[y];
		as[qs[i].id]=ans;
	}
	for(int i=1;i<=q;++i)cout<<as[i]<<'\n';
	return 0;
}
