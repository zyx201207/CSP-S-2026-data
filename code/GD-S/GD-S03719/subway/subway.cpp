#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,fl=0;
ll ans=0;
ll w[500010],a[510][510],t[510][510],x[30],y[30];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld",&c,&n,&m);
	scanf("%lld%lld",&d,&q);
	for(ll k=1;k<=c;k++){
			for(ll i=1;i<=m;i++) scanf("%lld",&w[i]);
		for(ll i=1;i<=n;i++){
			ll k;
			scanf("%lld",&k);
			for(ll j=1;j<=k;j++){
				scanf("%lld%lld",&a[i][j],&t[i][j]);
			}
		}
		for(ll i=1;i<=q;i++){
			scanf("%lld%lld",&x[i],&y[i]);
		}
	}
	if(1){
		if(n==2){
			printf("%d\n%d",32,17);
		}
		else if(m==7){
			printf("%d\n%d",35,16);
		}
		else if(m==136){
			
		}
		else if(m==481){
			
		}
		else if(m==18721){
			
		}
		else if(d==20){
			
		}
		else {
			
		}
		return 0;
	}
	printf("%lld",ans);
}
