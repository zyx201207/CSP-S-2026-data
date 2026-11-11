#include<bits/stdc++.h>
#define pii pair<long long,int>
using namespace std;
const int N=2e6+100;
const int M=2e3+100;
int head[N],bx,nxt[N],c,n,m,dd,qt,a[N],d[N],dep[N];
long long val[N],t[N],dis[N],inf[1],dist[M][M],ww[N];
bool vis[N];
void addedge(int u,int v,long long w){
	d[++bx]=v;
	nxt[bx]=head[u];
	val[bx]=w;
	head[u]=bx;
}
void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=2*m;i++) dis[i]=inf[0];
	for(int i=1;i<=2*m;i++) vis[i]=0;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=d[i];
			if(dis[v]>dis[u]+val[i]){
				dis[v]=dis[u]+val[i];
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
void dijkstra2(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=2*m;i++) dist[s][i]=inf[0];
	for(int i=1;i<=2*m;i++) vis[i]=0;
	dist[s][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=d[i];
			if(dist[s][v]>dist[s][u]+val[i]){
				dist[s][v]=dist[s][u]+val[i];
				q.push(make_pair(dist[s][v],v));
			}
		}
	}
}
void bfs(int s,int t){
	queue<int> q;
	for(int i=m+1;i<=2*m;i++) dep[i]=-1;
	q.push(s);
	dep[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=d[i];
			if(dep[v]>=0) continue;
			if(v<=m) continue;
			q.push(v);
			dep[v]=dep[u]+1;
			if(v==t) break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(inf,0x3f,sizeof(inf));
	cin>>c>>n>>m>>dd>>qt;
	for(int i=1;i<=m;i++){
		long long w;
		cin>>w;
		ww[i]=w;
		if(m<=1e3) addedge(i,i+m,w);
		if(m<=1e3) addedge(i+m,i,w);
	}
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=num;j++) for(int nt=1;nt<=num;nt++) if(j!=nt) addedge(a[j]+m,a[nt]+m,t[j]+t[nt]);
	}
	if(m>1e3){
		for(int i=1;i<=qt;i++){
			int x,y;
			cin>>x>>y;
			bfs(x+m,y+m);
			cout<<dep[y+m]*t[1]*2+ww[x]+ww[y]<<"\n";
		}
		return 0;
	}
	if(qt>2e3){
		for(int i=1;i<=m;i++){
			dijkstra2(i);
		}
		for(int i=1;i<=qt;i++){
			int x,y;
			cin>>x>>y;
			cout<<dist[x][y]<<"\n";
		}
	}else{
		for(int i=1;i<=qt;i++){
			int x,y;
			cin>>x>>y;
			dijkstra(x);
			cout<<dis[y]<<"\n";
		}
	}
	return 0;
}
