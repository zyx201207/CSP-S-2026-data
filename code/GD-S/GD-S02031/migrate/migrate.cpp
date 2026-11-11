#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000020],head[20000020],cnt=1,vis[2000020],d[2000020],d2[2000020];
struct edge{
	ll v,w,n;
}e[40000040];
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
		d[i]=1e18+10,vis[i]=0,d2[i]=0;
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
			if(d[v]>d[u]+e[i].w){
				d2[v]++;
			}
		}
	}
	return d[y];
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(T--){
		ll n,d,ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d&&x[i]!=x[j]){
					add(i,j,abs(x[i]-x[j]));
					add(j,i,abs(x[i]-x[j]));
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(dij(x[i],x[j])!=1e18+10){
					if(d2[x[j]]==2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
