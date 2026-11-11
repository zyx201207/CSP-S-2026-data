#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n,m,v[200005];
ll mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld",&n,&m);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&v[i]);
		mx=max(v[i],mx);
	}
	if(m==1) {
		printf("%lld",mx);
		return 0;
	}
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<i;++j){
			ll q=v[i]&v[j];
			mx=max(mx,q);
		}
	}
	printf("%lld",mx);
	
	return 0;
}
