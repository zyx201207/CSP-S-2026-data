#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10,M=555;
ll c,n,m,d,q,x,y,w[N],k[M],dp[M][M];
vector<ll> a[M],b[N];
map<pair<ll,ll>,ll> t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1,au,tu;j<=k[i];j++){
			cin>>au>>tu;
			a[i].emplace_back(au);
			t[{i,au}]=tu;
			b[au].emplace_back(i);
		}
	}
	for(ll i=0;i<=535;i++){
		for(ll j=0;j<=535;j++){
			dp[i][j]=INT_MAX;
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll ja=0;ja<b[i].size();ja++){
			for(ll jb=ja+1;jb<b[i].size();jb++){
				dp[ja][jb]=min(dp[ja][jb],t[{b[i][ja],i}]+t[{b[i][jb],i}]);
			}
		}
		ll mn=INT_MAX,res=0;
		for(ll j=0;j<b[i].size();j++){
			if(mn>t[{b[i][j],i}]){
				mn=t[{b[i][j],i}];
				res=b[i][j];
			}
		}
		if(mn==INT_MAX) continue;
		for(ll j=1;j<=n;j++){
			dp[j][res]=mn;
		}
	}
	while(q--){
		cin>>x>>y;
		ll ans=INT_MAX;
		for(ll i=0;i<k[x];i++){
			for(ll j=0;j<k[y];j++){
				ans=min(ans,dp[b[x][i]][b[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
