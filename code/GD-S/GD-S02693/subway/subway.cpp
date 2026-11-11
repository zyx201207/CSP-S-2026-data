#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define ll long long
inline ll read(){
	ll f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-') f=-1;
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
} 
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const ll N=5e5+10;
ll c,n,m,d,q,inf=0x3f3f3f3f3f3f3f3f;
ll w[N],k[N],tot;
ll linemp[N],rlinemp[N*22];
ll stamp[N][25];
pair<ll,ll> rstamp[N*22];
struct node{
	ll to,dist;
};
struct cmp{
	bool operator()(node a,node b){
		return a.dist>b.dist;
	}
};
vector<node> g[N];
inline void glink(ll u,ll v,ll w){
	g[u].push_back({v,w}),g[v].push_back({u,w});
}
inline ll solve(ll x,ll y){
	priority_queue<node,vector<node>,cmp> q;
	vector<ll> ans(n*22,inf);
	ans[x]=0,q.push({x,0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.dist>ans[u.to]) continue;
		if(u.to==y) return u.dist;
		for(ll i=0;i<g[u.to].size();i++){
			ll v=g[u.to][i].to,w=g[u.to][i].dist;
			if(ans[v]>u.dist+w) ans[v]=u.dist+w,q.push({v,ans[v]});
		}
	}
	return ans[y];
}
/*struct ask{
	ll x,y,id;
}qry[N];
vector<pair<ll,ll>> ak[N];*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),m=read(),n=read(),d=read(),q=read();
	tot=n;
	for(ll i=1;i<=n;i++) w[i]=read();
	for(ll i=1;i<=m;i++){
		k[i]=read();linemp[i]=++tot,rlinemp[tot]=i;
		for(ll j=1;j<=k[i];j++){
			ll x=read(),y=read();
			stamp[x][i]=++tot,rstamp[tot]={x,i};
			glink(linemp[i],stamp[x][i],0);
			glink(stamp[x][i],x,y);
		}
	}
	while(q--){
		ll x=read(),y=read();
		write(solve(x,y)+w[x]+w[y]),putchar('\n');
	}
	/*for(ll i=1;i<=q;i++){
		qry[i].id=i,qry[i].x=read(),qry[i].y=read();
		if(ak[qry[i].x].empty()) ak[qry[i].x].push_back(qry[i].y);
		else 
	}*/
	return 0;
}//Oct31==Dec25?
