#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,inf=0x3f3f3f3f,M=2e6+5;
int c,t,n,dist[N],cs[N];
bool vis[N];
ll x[M],d;
struct Edge{
	int to,next;
}e[N*2];
int head[N],cnt,ans;
void add(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt;
}
struct Node{
	int u,dis;
};
queue<Node> q;
void dijkstra(int u){
	for(int i=1;i<=n;i++) cs[i]=0,dist[i]=inf,vis[i]=false;
	cs[u]=1,dist[u]=0,q.push({u,dist[u]});
	while(!q.empty()){
		Node t=q.front();q.pop();
		if(vis[t.u]) continue;
		vis[t.u]=true;
		for(int i=head[t.u];i;i=e[i].next){
			int v=e[i].to;
			if(dist[v]>t.dis+1){
				dist[v]=t.dis+1,cs[v]=cs[t.u];
				q.push({v,dist[v]});
			} 
			else if(dist[v]==t.dis+1) cs[v]+=cs[t.u];
		} 
	} 
	for(int i=1;i<=u;i++) if(cs[i]==2) ans++;
}
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(c<=10){
		cnt=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d)  add(i,j),add(j,i);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) dijkstra(i);
		return cout<<ans<<"\n",void();
	}
	if(c==11||c==12){
		if(n<2) return cout<<0<<"\n",void();
		ll gc=x[2]-x[1];
		if(gc>d) return cout<<0<<"\n",void();
		int w=d/gc;
		if(w==1) return cout<<0<<"\n",void();
		w*=2;
		return cout<<max(n-w+1,0)<<"\n",void();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) work();
	return 0;
}

/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
