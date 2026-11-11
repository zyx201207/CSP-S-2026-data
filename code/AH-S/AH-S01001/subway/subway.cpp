#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
bool vis[N][N];
int c,n,m,d,Q,k[N],u,se,hd[N],l,r;
long long w[M],dis[N][N],v,bian[N][N];
struct E {int nxt,to; long long c;} Edge[M<<1];
struct node {int Sub;long long t;};
struct node2 {
    int u;long long dis;
    bool operator > (const node2 &x) const {
	    return dis>x.dis;
	}
};
map <int,node> x[M];
int cnt[M];
priority_queue <node2,vector<node2>,greater<node2> > q;
void add(int u,int v,long long w) {
	Edge[++se].nxt=hd[u];
	Edge[se].to=v,Edge[se].c=w,hd[u]=se;
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++) {
			scanf("%d %lld",&u,&v);
			x[u][++cnt[u]]=((node) {i,v});
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) bian[i][j]=1e18;
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=cnt[i];j++) {
			for(int k=1;k<j;k++) {
				node a=x[i][j],b=x[i][k];
				if(a.t+b.t<bian[a.Sub][b.Sub]) {
				    bian[a.Sub][b.Sub]=a.t+b.t;
				    add(a.Sub,b.Sub,a.t+b.t);
				    add(b.Sub,a.Sub,a.t+b.t);
			    }
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) dis[i][j]=1e18,vis[i][j]=false;
		q.push((node2) {i,0}),dis[i][i]=0;
		while(!q.empty()) {
			node2 tmp=q.top(); q.pop();
			int U=tmp.u;
			if(vis[i][U]) continue;
			vis[i][U]=true;
			for(int p=hd[U];p;p=Edge[p].nxt) {
				int V=Edge[p].to;
				if(dis[i][U]+Edge[p].c<dis[i][V]) {
					dis[i][V]=dis[i][U]+Edge[p].c;
					q.push((node2) {V,dis[i][V]});
				}
			}
		}
	}
	while(Q--) {
		scanf("%d %d",&l,&r);
		long long ans=1e18;
		for(int i=1;i<=cnt[l];i++) {
			for(int j=1;j<=cnt[r];j++) {
				long long t=w[l]+x[l][i].t+dis[x[l][i].Sub][x[r][j].Sub]+x[r][j].t+w[r];
				ans=min(ans,t);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

