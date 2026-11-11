#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	vector<ll>v;
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<n;i++){
		scanf("%lld",a+i);
		v.push_back(a[i]);
	}
	for(ll i=30;i>=1;i--){
		vector<ll>t;
		ll len=v.size();
		for(ll j=0;j<len;j++){
			if(v[j]&(1<<(i-1))) t.push_back(v[j]);
		}
		if(ll(t.size())>=m) v=t;
		if(ll(v.size())==m) break;
	}
	ll ans=v[0];
	if(ll(v.size())<m){
		printf("0");
		return 0;
	}
	for(ll i=1;i<m;i++) ans = ans&v[i];
	printf("%lld",ans);
	return 0;
}
