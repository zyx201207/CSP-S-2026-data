#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=500;
ll const maxm=5e5;
ll const inf=1e18;
ll C,n,m,d,q;
ll w[maxm+1];
struct node{
	ll v,t;
};
vector<node>vt[maxm+1];
ll to[maxn+1][maxn+1];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll si;
		cin>>si;
		for(ll j=1;j<=si;j++){
			ll a,t;
			cin>>a>>t;
			vt[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			to[i][j]=inf;
		}
		to[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<vt[i].size();j++){
			for(ll k=j+1;k<vt[i].size();k++){
				ll av=vt[i][j].v;
				ll at=vt[i][j].t;
				ll bv=vt[i][k].v;
				ll bt=vt[i][k].t;
				to[av][bv]=min(to[av][bv],at+bt);
				to[bv][av]=min(to[bv][av],at+bt);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				to[i][j]=min(to[i][j],to[i][k]+to[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=inf;
		for(ll j=0;j<vt[x].size();j++){
			for(ll k=0;k<vt[y].size();k++){
				ll av=vt[x][j].v;
				ll at=vt[x][j].t;
				ll bv=vt[y][k].v;
				ll bt=vt[y][k].t;
				ans=min(ans,to[av][bv]+at+bt+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}
