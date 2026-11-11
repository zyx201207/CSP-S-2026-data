#include <iostream>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
ll sub[500005][50][2],w[500005],xnum[500005];
ll dp[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		ll num;
		cin>>num;
		for(ll j=1;j<=num;j++){
			ll a,t;
			cin>>a>>t;
			for(ll k=1;k<=xnum[a];k++){
				dp[i][sub[a][k][0]]=min(dp[i][sub[a][k][0]],t+sub[a][k][1]);
				dp[sub[a][k][0]][i]=dp[i][sub[a][k][0]];
			}
			sub[a][++xnum[a]][0]=i;
			sub[a][xnum[a]][1]=t;
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(ll u1=1;u1<=xnum[x];u1++){
			for(ll v1=1;v1<=xnum[y];v1++){
				ll u=sub[x][u1][0],v=sub[y][v1][0];
				ans=min(ans,dp[u][v]+sub[x][u1][1]+sub[y][v1][1]);		
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

