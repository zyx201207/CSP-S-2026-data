#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector> 
#include<queue> 
#define ll long long
#define pll pair<ll,ll>
#define il inline
#define re register int
#define rl register ll
#define gc getchar
using namespace std;
const int MN=5e5+5; 
ll cid,n,m,D,Q,w[MN],k[MN],d[MN],ans[MN],st[MN],ed[MN],tot,head[MN],dis[505][505];bool vis[MN];
vector<ll> l[MN],t[MN];vector<pll> to[MN],p[MN];
priority_queue<pll,vector<pll>,greater<pll> >q;
struct edge{ll to,nxt,w;}e[505*505*40+5];
il ll read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(rl x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
il void add(rl u, rl v, rl w){e[++tot]={v,head[u],w};head[u]=tot;}
il void dijkstra(rl s){
	for(re i=1; i<=n; ++i) d[i]=1e18,vis[i]=0;
	while(!q.empty()) q.pop();
	q.push({d[s]=0,s});while(!q.empty()){
		ll u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(re i=head[u]; i; i=e[i].nxt){
			ll v=e[i].to,w=e[i].w;
			if(d[v]>d[u]+w) q.push({d[v]=d[u]+w,v});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid=read();n=read();m=read();D=read();Q=read();
	for(re i=1; i<=m; ++i) w[i]=read();
	for(re i=1; i<=n; ++i){
		k[i]=read();
		for(re j=1; j<=k[i]; ++j){
			ll a=read(),tm=read();
			t[i].push_back(tm);l[i].push_back(a);p[a].push_back({i,tm});
		}
	}
	for(re i=1; i<=n; ++i) for(re j=0; j<l[i].size(); ++i){
		ll u=l[i][j],t1=t[i][j];for(re k=0; k<p[u].size(); ++k){
			ll l2=p[u][k].first,t2=p[u][k].second;
			add(i,l2,t1+t2);add(l2,i,t1+t2);
		}
	}
	for(re i=1; i<=n; ++i){
		dijkstra(i);
		for(re j=1; j<=n; ++j) dis[i][j]=d[j];
	}
	while(Q--){
		ll u=read(),v=read(),ans=1e18;
		for(re i=0; i<p[u].size(); ++i) for(re j=0; j<p[v].size(); ++j){
			ll l1=p[u][i].first,t1=p[u][i].second,l2=p[v][j].first,t2=p[v][j].second;
			ans=min(ans,t1+t2+dis[l1][l2]);
		}
		write(ans+w[u]+w[v]);putchar('\n');
	}
	return 0;
}//261031
