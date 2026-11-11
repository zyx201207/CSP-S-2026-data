#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d;
vector<ll>a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			ll x;
			scanf("%lld",&x);
			a.push_back(x);
		}ll pubd=a[1]-a[0];
		if(pubd>d){
			printf("0\n");
			continue;
		}else{
			ll nk=d/pubd;
			if(nk<=1||n<=2){
				printf("0\n");
				continue;
			}ll ans=n-nk-1;
			if(ans<0)printf("0\n");
			else printf("%lld\n",ans);
		}
	}
    return 0;
}
