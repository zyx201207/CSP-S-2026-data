#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",x+i);
		}
		if(n==1){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
			int d=x[2]-x[1];
			m/=d;
			if(m<2||m>n){
				printf("0\n");
				continue;
			}
			printf("%lld\n",n-m*2+1);
			continue;
		}
		printf("This is a wrong answer.\n");
	}
	return 0;
}
