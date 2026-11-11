#include<bits/stdc++.h>
using namespace std;
long long d,x[2000005],n,m,c,t,k,s,o;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scnaf("%lld%lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		if(n<=3)
			printf("\n",0);
		else{
			k=0,s=x[2]-x[1];
			o=d/s;
			k=n-2*o+1;
			scnaf("%lld\n",k);
		}
	}
	return 0;
}
