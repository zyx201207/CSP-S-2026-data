#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
using ll=long long;
ll read(){
	ll x=0;
	int f=1,ch=gc();
	while (!isdigit(ch)) {
		f=(ch=='-'?-1:f);
		ch=gc();
	}
	while (isdigit(ch)){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
void write(ll x){
	if (x>9) write(x/10);
	pc(x%10+'0');
}
struct sta{
	int v;
	ll t;
	int x,u;
}; 
struct cmp{
	bool operator()(const sta&a,const sta&b){
		return a.t>b.t;
	}
};
const int maxm=5e5+5;
vector <sta> g[maxm];
int a[maxm],ti[1005][505];
ll dis[1005][1005];
void dijkstra(int s){
	priority_queue<sta,vector<sta>,cmp> q;
	memset(dis[s],0x3f,sizeof dis);
	for (sta &p:g[s]) {
		q.push({p.v,ti[s][p.x],p.x,s});
	}
	dis[s][s]=0;
	while (!q.empty()){
		int v=q.top().v;
		ll t=q.top().t,x=q.top().x,u=q.top().u,d;
		q.pop();
		if (t!=dis[s][u]){
			continue;
		}
		for (sta &p:g[v]){
			if (x!=p.x){
				d=t+ti[v][x]+ti[v][p.x];
			}
			else {
				d=t;
			}
			if (d<dis[s][v]){
				dis[s][v]=d;
				q.push({p.v,d,p.x,v});
			}
		}
	}
}
void sol1(int n,int m,int q){
	for (int i=1;i<=n;i++){
		dijkstra(i);
	}
	for (int i=1;i<=q;i++){
		int x=read(),y=read();
		write(dis[x][y]+a[x]+a[y]);
		pc('\n');
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for (int i=1;i<=m;i++){
		a[i]=read();
	}
	for (int i=1;i<=n;i++){
		int k=read(),lst;
		for (int j=1;j<=2*k;j++){
			int u;
			cin >> u;
			if (j==1){
				lst=u;
				continue;
			}
			if (j%2){
				g[u].push_back({lst,0,i});
				g[lst].push_back({u,0,i});
			}
			else {
				ti[lst][i]=u;
			}
		} 
	}
	if (c<=11) {
		sol1(n,m,q);
		return 0;
	}
}
