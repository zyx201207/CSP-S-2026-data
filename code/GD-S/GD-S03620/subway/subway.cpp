#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pir pair<ll,ll>
#define endl '\n'
void dyr(){
	ll c,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	vector<ll> w(m+1);
	vector<vector<pir>> a(m+1);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		ll l,r,k;
		scanf("%lld",&r);
		for(ll j=1;j<=r;j++){
			scanf("%lld %lld",&l,&k);
			a[l].push_back({i,k});
		}
	}
	vector<vector<ll>> maze(n+1,vector<ll>(n+1,1e18));
	vector<vector<ll>> use(n+1,vector<ll>(n+1));
	for(ll i=1;i<=m;i++){
		for(auto it:a[i]){
			for(auto itt:a[i]){
				if(it.first==itt.first) continue;
				if((it.second+itt.second)<maze[it.first][itt.first]){
					maze[it.first][itt.first]=(it.second+itt.second);
					use[it.first][itt.first]=i;
				}
			}
		}
	}
	for(ll i=1;i<=n;i++){
		maze[i][i]=0;
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if((maze[i][k]+maze[k][j])<maze[i][j]){
					maze[i][j]=maze[i][k]+maze[k][j];
					use[i][j]=use[i][k];
				}
			}
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ll ans=1e18,pd=0,us,uss;
		for(auto it:a[u]){
			for(auto itt:a[v]){
				us=use[it.first][itt.first];
				uss=use[itt.first][it.first];
				pd=maze[it.first][itt.first];
				if(u!=us&&u!=uss) pd+=it.second;
				if(v!=us&&v!=uss) pd+=itt.second;
				ans=min(ans,pd);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	} 
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
