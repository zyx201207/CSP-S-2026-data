/*
% hZk
AKAKAKAK
*/
#include<bits/stdc++.h>
#define N 500005
#define M 505
#define ll long long
using namespace std;

vector<pair<ll,ll>>G[N];
ll c,n,m,d,q,w[N],dp[M][M],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll kf;
		cin>>kf;
		for(ll j=1;j<=kf;j++){
			ll pp,vv;
			cin>>pp>>vv;
			G[pp].push_back({i,vv});
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(ll i=1;i<=n;i++)dp[i][i]=0;
	for(ll i=1;i<=m;i++){
		for(auto to1:G[i]){
			for(auto to2:G[i]){
				ll v1=to1.first;
				ll w1=to1.second;
				ll v2=to2.first;
				ll w2=to2.second;
				if(v1==v2)continue;
				dp[v1][v2]=min(dp[v1][v2],w1+w2);
				dp[v2][v1]=min(dp[v2][v1],w1+w2);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		ll ans=dp[0][0];
		for(auto to1:G[xr]){
			for(auto to2:G[yr]){
				ll v1=to1.first;
				ll w1=to1.second;
				ll v2=to2.first;
				ll w2=to2.second;
				ans=min(ans,w1+w2+dp[v1][v2]);
			}
		}
		cout<<ans+w[xr]+w[yr]<<"\n";
	}
	return 0;
}