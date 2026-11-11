#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll c,n,m,d,q;
ll dis[2002][2002]; 
ll cost[505][22];
ll w[2002],shu[505];
void build(){
	for(ll i=1;i<=2000;i++){
		for(ll j=1;j<=2000;j++){
			dis[i][j]=INT_MAX;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			for(ll k=1;k<=m;k++){
				if(k!=j&&cost[i][j]!=0&&cost[i][k]!=0){
					ll dist=cost[i][j]+cost[i][k];
					dis[j][k]=min(dis[j][k],dist);
				}
			}
		}
	}
	for(ll k=1;k<=m;k++){ 
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=m;j++){
				if(k!=i&&k!=j&&i!=j&&dis[i][k]!=INT_MAX&&dis[k][j]!=INT_MAX){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)	cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>shu[i];
		for(ll j=1;j<=shu[i];j++){
			ll x,y;	cin>>x>>y;
			cost[i][x]=y;
		}
	}
	build();
	for(ll i=1;i<=q;i++){
		ll a,b;	cin>>a>>b;
		cout<<dis[a][b]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	solve();
	return 0;
}
