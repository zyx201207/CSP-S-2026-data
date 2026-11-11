#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXK 500005
#define MAXN 505
#define MAXQ 100005

ll n,m,c,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	int w[m+5],t[n+5][MAXK];
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k; cin>>k;
		for(ll j=1;j<=k;j++){
			ll temp;cin>>temp>>t[i][j];
		}
	}
	while(q--){
		ll x,y; cin>>x>>y;
		ll ans=0;
		ans+=(w[x]+w[y]);
		for(int i=x;i<=y;i++){
			ans+=t[1][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
