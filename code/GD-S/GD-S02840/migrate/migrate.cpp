#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll c,t,n,d;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(c==11||c==12){
			if(a[2]-a[1]>(d>>1ll))printf("0\n");
			else printf("%lld\n",n-(lower_bound(a+1,a+1+n,d)-a-1)+1);
		}
	}return 0;
}

