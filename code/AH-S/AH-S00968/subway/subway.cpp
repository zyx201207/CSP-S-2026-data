#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define ull unsigned ll
#define ll long long
using namespace std;
ll n,m,d,q,w[500010],dp[510][510];
vector < pair < ll , ll > > a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>n>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	ll i,j,k,l;
	rep(i,1,n,1) cin>>w[i];
	rep(i,1,m,1){
		cin>>l;
		rep(j,1,l,1){
			cin>>k>>d;
			a[k].push_back({i,d});
		}
	}
	rep(i,1,n,1) for(auto u : a[i]) for(auto v : a[i]) if(u != v)
		dp[u.first][v.first] = dp[v.first][u.first] = min(dp[v.first][u.first],u.second + v.second);
	rep(i,1,m,1) dp[i][i] = 0;
	rep(k,1,m,1) rep(i,1,m,1) rep(j,1,m,1) dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
	while(q--){
		ll u,v,ans = 0x3f3f3f3f3f3f3f3fll;
		cin>>u>>v;
		for(auto x : a[u]) for(auto y : a[v]) ans = min(ans,dp[x.first][y.first] + x.second + y.second);
		cout<<w[u] + w[v] + ans<<'\n';
	}
	return 0;
}

