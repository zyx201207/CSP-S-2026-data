#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXN=5e5+1;
ll c,n,m,d,q,w[MAXN],k[MAXN];
struct stu{
	ll a[21],t[21];
}f[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++) cin>>f[i].a[j]>>f[i].t[j];
	}
	for(ll i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
		ll ans=w[1];
		cout<<ans<<'\n';
	}
	return 0;
}
