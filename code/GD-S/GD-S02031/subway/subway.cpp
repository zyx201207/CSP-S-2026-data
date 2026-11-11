#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w[550000],k[550000],head[550000],cnt=1,vis[550000],d[550000];
struct tz{
	ll dtz,t;
}xza[550];
struct edge{
	ll v,w,n;
}e[1100000];
void add(ll u,ll v,ll w){
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].n=head[u];
	head[u]=cnt++;
}
struct node{
	ll u,d;
	bool operator < (const node& v) const {
		return v.d<d;
	}
};
priority_queue<node> pq;
ll dij(ll x,ll y){
	for(ll i=0;i<=505000;i++){
		d[i]=1e18+10,vis[i]=0;
	}
	d[x]=0;
	pq.push({x,0});
	while(!pq.empty()){
		ll u=pq.top().u;
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(ll i=head[u];i;i=e[i].n){
			ll v=e[i].v;
			if(d[v]>d[u]+e[i].w){
				d[v]=d[u]+e[i].w;
				if(vis[v]==0){
					pq.push({v,e[i].w});
				}
			}
		}
	}
	return d[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q,xz=0;
	cin>>c>>n>>m>>d>>q;
	if(c>=9&&c<=11){
		xz=1;
	}else if(c>=12&&c<=19){
		xz=2;
	}else if(c>=20&&c<=21){
		xz=3;
	}else if(c>=22&&c<=23){
		xz=4;
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=2*k[i];j+=2){
			ll a,t;
			cin>>a>>t;
			add(i+500,a,t);
			add(a,i+500,t);
			if(xz==1){
				if(xza[i].dtz==0){
					xza[i].dtz=a;
					xza[i].t=t;
				}else{
					add(xza[i].dtz,a,xza[a].t+t);
					add(a,xza[i].dtz,xza[a].t+t);
				}
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<"\n";
	}
	return 0;
}
