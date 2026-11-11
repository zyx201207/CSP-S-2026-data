#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,Q=1e5+10,INF=0x3f3f3f3f;
int n,m,d,q;
int x[Q],y[Q];
int cnt;
bool vis[N],done[N];
int dist[N],head[N];
int w[N],k[N];
vector<int>e[N];
struct sub{
	vector<int>a;
	vector<int>t;
}su[510];
struct edge{
	int v,w,nxt;
}E[100*N];
void add(int u,int v,int w){
	E[++cnt].v=v;
	E[cnt].w=w;
	E[cnt].nxt=head[u];
	head[u]=cnt;
}
struct node{
	int id,dis;
	const operator < (const node &x)const{return dis>x.dis;}
};
void dij(int s){
	for(int i=1;i<=m;i++)dist[i]=INF,vis[i]=0;
	priority_queue<node>q;
	node ss;
	dist[s]=0;
	ss.id=s,ss.dis=0;
	q.push(ss);
	while(!q.empty()){
		node u=q.top();
		q.pop();
		for(int i=head[u.id];i;i=E[i].nxt){
			int v=E[i].v;
			if(vis[v])continue;
			vis[v]=1;
			if(dist[v]>u.dis+E[i].w){
				dist[v]=u.dis+E[i].w;
				node vv;
				vv.id=v,vv.dis=dist[v];
				q.push(vv);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int x,y;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&x,&y);
			su[i].a.push_back(x);
			su[i].t.push_back(y);
			e[x].push_back(i);
		}
		
	}
	int ww[N];
	for(int u=1;u<=m;u++){
		memset(done,0,sizeof(done));
		memset(ww,0x3f,sizeof(ww));
		for(auto i:e[u]){
			int tt;
			for(int j=0;j<k[i];j++){
				if(u==su[i].a[j]){
					tt=su[i].t[j];
					break;
				}
			}
			for(int j=0;j<k[i];j++){
				if(u==su[i].a[j])continue;
				done[su[i].a[j]]=1;
				ww[su[i].a[j]]=min(ww[su[i].a[j]],su[i].t[j]+tt);
			}
		}
		for(int i=1;i<=m;i++){
			if(done[i]){
				add(u,i,ww[i]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
		dij(x[i]);
		printf("%d\n",w[x[i]]+w[y[i]]+dist[y[i]]);
	}
	return 0;
}
