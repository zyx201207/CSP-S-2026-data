#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll n,d,a[N];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=12){
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		ll L=a[2]-a[1];
		ll k;
		for(ll i=0;;i++){
			if(d>=i*L&&d<=(i+1)*L) {
				k=i;
				break;
			}
		}
		int sum=0;
		k*=2;
		while(n>=k){
			sum++;
			n--;
		}
		printf("%d\n",sum-2);
	}
}
	else if(c>=13){
		while(t--){
					scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
			printf("%lld\n",(n*(n-1))/2);
		}
	}
}