#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=510,M=5e5+10;
const ll inf=1e16;
ll val[M][22],w[M],id[M][22],tot[M];
ll dis[N][N]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			tot[a]++;
			id[a][tot[a]]=i;
			val[a][tot[a]]=t;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
//		cout<<" "<<i<<" "<<tot[i]<<"\n";
		for(ll j=1;j<=tot[i];j++){
			for(ll k=j+1;k<=tot[i];k++){
				ll u=id[i][j],wu=val[i][j];
				ll v=id[i][k],wv=val[i][k];
//				cout<<u<<" "<<v<<" "<<j<<" "<<k<<" "<<wu+wv<<"\n";
				dis[u][v]=dis[v][u]=min(dis[u][v],(ll)(wu+wv));
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(dis[i][k]==inf||dis[j][k]==inf) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=1e16;
		for(ll i=1;i<=tot[x];i++){
			for(ll j=1;j<=tot[y];j++){
				ll u=id[x][i],du=val[x][i];
				ll v=id[y][j],dv=val[y][j];
//				cout<<u<<" "<<v<<"\n";
//				cout<<w[x]<<" "<<w[y]<<" "<<du<<" "<<dv<<" "<<dis[u][v]<<"\n";
				ans=min(ans,w[x]+w[y]+du+dv+dis[u][v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
