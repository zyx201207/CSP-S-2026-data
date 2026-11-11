#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,c,q,val[N],k[N],dp[1000][1000],d;
vector<ll>e[N],w[N],l[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>val[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1,d,dt;j<=k[i];j++){
			cin>>d>>dt;
			w[d].push_back(i);
			l[d].push_back(dt);
		}
	}for(ll i=1;i<=m;i++){
		for(ll j=0;j<w[i].size();j++){
			for(ll k=0;k<w[i].size();k++){
				dp[w[i][j+1]][w[i][k+1]]=dp[w[i][k+1]][w[i][j+1]]=min(dp[w[i][k+1]][w[i][j+1]],l[i][j+1]+w[i][k+1]);
			}
		}
	}cout<<1;
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(ll a=1,u,v;a<=q;a++){
		cin>>u>>v;
		ll ans=1000000000000000000;
		for(ll j=0;j<w[u].size();j++){
			for(ll k=0;k<w[v].size();k++){
				ans=min(ans,dp[w[u][j+1]][w[v][k+1]]+l[u][j+1]+l[v][k+1]);
			}
		}cout<<ans;
	}
	return 0; 
}
