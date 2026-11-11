#include<bits/stdc++.h>
#define ll long long
#define p pair<ll,int> 
using namespace std;
int n,m,ki,ai,d,q,c,head[500505],cnt,tot,xi,yi;
ll wi[500005],ti,dis[500505];
bool vis[500505];
priority_queue<p,vector<p>,greater<p> > que;
struct edge{
	int to,next;
	ll w;
} e[1500005];
void link(int x,int y,ll z) {
	++tot;
	e[tot].to=y;
	e[tot].next=head[x];
	e[tot].w=z;
	head[x]=tot;
}
ll D(int d,int s) {
	while(!que.empty()) {
		que.pop();
	}
	int u,v;
	for(int i=1;i<=cnt;i++) {
		dis[i]=1e18;
		vis[i]=false;
	}
	dis[d]=0;
	que.push({0,d});
	while(!que.empty()) {
		u=que.top().second;
		if(u==s) return dis[u];
		que.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=e[i].next) {
			v=e[i].to;
			if(dis[u]+e[i].w<dis[v]) {
				dis[v]=dis[u]+e[i].w;
				que.push({dis[v],v});
			}
		}
	}
	return 0;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) {
		scanf("%lld",wi+i);
	}
	cnt=m;
	for(int i=1;i<=n;i++) {
		scanf("%d",&ki);
		cnt++;
		for(int j=1;j<=ki;j++) {
			scanf("%d%lld",&ai,&ti);
			link(ai,cnt,ti);
			//cout<<ai<<" "<<cnt<<endl;
			link(cnt,ai,ti);
		}
	}
	while(q--) {
		scanf("%d%d",&xi,&yi);
		printf("%lld\n",D(xi,yi)+wi[xi]+wi[yi]);
	}
	return 0;
}
