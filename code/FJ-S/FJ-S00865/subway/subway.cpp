#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
ll w[500025];
struct node{
	ll id,v;
};
vector<node> g[500025];
vector<node> a[525];
ll f[525][525];
struct node2{
	ll s,t,id;
};
vector<node2> Q[525];
ll mi[500025];
ll ans[100025]; 
ll c[500025];
ll cnt=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll C,n,m,d,q;
	cin>>C>>n>>m>>d>>q;
	R(i,1,m)cin>>w[i];
	R(i,1,n){
		ll k;
		cin>>k;
		R(j,1,k){
			ll x,v;
			cin>>x>>v;
			a[i].push_back((node){x,v});
			g[x].push_back((node){i,v});
		}
	}
	R(i,1,n)R(j,1,n){
		if(i==j)f[i][j]=0;
		else f[i][j]=1e17;
	}
	R(i,1,m){
		ll t=g[i].size();
		R(j,0,t-1){
			R(k,j+1,t-1){
				ll u=g[i][j].id,v=g[i][k].id;
				f[u][v]=min(f[u][v],g[i][j].v+g[i][k].v);
				f[v][u]=f[u][v];
			}
		}
	}
	R(k,1,n)R(i,1,n)R(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	R(i,1,q){
		ll s,t;
		cin>>s>>t;
		ans[i]=1e17;
		for(auto v:g[s])Q[v.id].push_back((node2){v.v+w[s],t,i});
	}
	R(i,1,n){
		cnt=0;
		for(auto vv:Q[i])c[++cnt]=vv.t;
		sort(c+1,c+1+cnt);
		cnt=unique(c+1,c+1+cnt)-c-1;
		R(J,1,cnt){
			ll j=c[J];
			mi[j]=1e17;
			for(auto vv:g[j]){
				ll id=vv.id,v=vv.v;
				mi[j]=min(mi[j],f[i][id]+v);
			}
		}
		for(auto vv:Q[i]){
			ll s=vv.s,t=vv.t,id=vv.id;
			ans[id]=min(ans[id],s+mi[t]+w[t]);
		}
	}
	R(i,1,q)cout<<ans[i]<<'\n';
	return 0;
}
//15:12
//15:18 TLE 6s??? but answer correct
//15:20 O2 on, 6s->1.45s
//15:32 kachang 1.45s->0.6s
//15:34 AC
