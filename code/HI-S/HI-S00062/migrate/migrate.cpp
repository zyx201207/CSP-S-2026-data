#include<bits/stdc++.h>
using namespace std;
int C,T;
long long c[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&C);
	scanf("%d",&T);
	while(T--){
		long long int a;long long b;
		scanf("%lld",&a);scanf("%lld",&b);
		for(long long i=0;i<a;i++){
			scanf("%lld",&c[i]);
		}
		if(a<=3) printf("0\n");
		else{
			b=b/abs(c[0]-c[1]);
			if(b>=2&&a+1>2*b){
				printf("%lld\n",a-(b*2)+1);
			}else{
				printf("0\n");
			}
		}
	}
	return 0;
}
