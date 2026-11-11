#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define INF 1000000000000000000
ll c,n,m,d,q,w[500005],g[505][505];
struct node{
	ll op,l;
};
vector<node> e[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=n;j++){
			if(i!=j){
				g[i][j]=INF;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}

	for(ll i=1;i<=m;i++){
		for(ll x=0;x<e[i].size();x++){
			for(ll y=x+1;y<e[i].size();y++){
				g[e[i][x].op][e[i][y].op]=g[e[i][y].op][e[i][x].op]=min(g[e[i][y].op][e[i][x].op],e[i][x].l+e[i][y].l);
			}
		}
	}

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i!=j){
				for(ll k=1;k<=n;k++){
					g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
	}
	
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<g[i][j]<<" ";
//		}cout<<endl;
//	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll t=INF;
		for(auto i:e[x]){
			for(auto j:e[y]){
				t=min(t,g[i.op][j.op]+i.l+j.l);
			}
		}
		cout<<t+w[x]+w[y]<<"\n";
	}
	return 0;
}
