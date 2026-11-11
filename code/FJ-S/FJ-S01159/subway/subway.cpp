#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,int> pli;
const int N=510,M=5e5+5,Q=1e5+5;
const int V=510100,E=2e7+100;
const ll INF=1e18;
struct node {
	int s,t;
	int id;
	int ans;
};
int c,n,m,d,q,tot,k,x,y,z;
int val[M];
int ver[E],edge[E],nxt[E],head[V];
node nd[Q];
ll dis[V];
bool vis[V];
priority_queue<pli> que;
bool cmp1(const node& u,const node& v) {
	return u.s<v.s;
}
bool cmp2(const node& u,const node& v) {
	return u.id<v.id;
}
void add(int u,int v,int w) {
	ver[++tot]=v;
	edge[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
void dijkstra(int s) {
	while(!que.empty()) que.pop();
	for(int i=1;i<=n+m;i++) {
		dis[i]=INF;
		vis[i]=false;
	}
	dis[s]=0;
	que.push({0ll,s});
	while(!que.empty()) {
		x=que.top().second;
		que.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=head[x];i;i=nxt[i]) {
			y=ver[i]; z=edge[i];
			if(dis[y]>dis[x]+z) {
				dis[y]=dis[x]+z;
				que.push({-dis[y],y});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>x>>z;
			add(x,m+i,z);
			add(m+i,x,z);
		}
	}
	for(int i=1;i<=q;i++) {
		cin>>nd[i].s>>nd[i].t;
		nd[i].id=i;
	}
	sort(nd+1,nd+1+q,cmp1);
	for(int i=1;i<=q;i++) {
		if(nd[i].s>nd[i-1].s) dijkstra(nd[i].s);
		nd[i].ans=dis[nd[i].t]+val[nd[i].s]+val[nd[i].t];
	}
	sort(nd+1,nd+1+q,cmp2);
	for(int i=1;i<=q;i++)
		cout<<nd[i].ans<<'\n';
	return 0;
}
// <= O((m+n)q log n) 
// 相信相信的力量吧
// 希望能 1=
