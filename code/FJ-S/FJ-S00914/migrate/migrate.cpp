#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,d;
ll s[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&s[i]);
		}
		if(n==1 || d<=s[2]-s[1]){
			printf("0\n");
			continue;
		}
		ll b=(d/(s[2]-s[1]))*2-1;
		printf("%lld\n",max(0ll,n-b));
	}
	return 0;
}
