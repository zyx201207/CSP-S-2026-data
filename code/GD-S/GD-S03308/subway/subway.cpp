#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
vector<ll>a;
vector<vector<ll>>b;
vector<vector<bool>>vis,vs;
ll dfs(ll l,ll r,ll ans){
	ll ans1=1e17;
	for(ll i=1;i<=m;i++){
		if(b[i][l]<1e17){
			if(b[i][r]!=1e17)ans1=min(b[i][l]+b[i][r],ans1);
			for(ll j=1;j<=m;j++){
				for(ll k=1;k<=n;k++){
					if(b[j][k]<1e17&&b[i][k]<1e17&&vis[i][j]==0){
						vis[i][j]=1;
						ans1=min(dfs(k,r,ans1+ans)+b[j][k]+b[i][k],ans1);
						vis[i][j]=0;
					}
				}
			}
			for(ll j=1;j<=m;j++){
				for(ll k=1;k<=n;k++){
					if(b[i][k]<1e17&&b[j][k]<1e17&&b[j][r]<1e17&&vs[i][k]==0){
						vs[i][k]=1;
						ans1=min(dfs(k,r,ans1+ans),ans1);
						vs[i][k]=0;
					}
				}
			}
		}
		
	}
	return ans1+ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	a.assign(m+5,0);
	vis.assign(m+5,vector<bool>(m+5,0));
	for(ll i=1;i<=n;i++)cin>>a[i];
	b.assign(m+5,vector<ll>(n+5,1e17));
	vs.assign(m+5,vector<bool>(n+5,0));
	for(ll i=1;i<=m;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;cin>>a>>t;
			b[i][a]=t;
		}
	}
	while(q--){
		ll l,r;cin>>l>>r;
		cout<<a[l]+dfs(l,r,0)+a[r]<<'\n';
	}
	return 0;
}

