#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+4;
ll c,t,n,d;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(x,0,sizeof(x));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		ll cha=x[2]-x[1];d/=cha;
		if(d==1){
			printf("0\n");continue;
		}
		ll ans=0;
		for(int i=2;d*i<=n;i++){
			ll sum=d*i-1;
			ans+=n-sum;
		}
		printf("%lld\n",ans);
	}
}
/*
0 1
4 3
1 3 5 7
17:52 完成特殊点 
快快抹干眼泪,看看昙花多美
昙花终会枯萎,因此永恒珍贵 
*/
