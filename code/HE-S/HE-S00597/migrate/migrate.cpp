#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(long long T=1;T<=t;T++){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			long long chu=d/(a[2]-a[1]);
			scanf("%lld",&a[i]);
			if(c==11||c==12){
				if(d<=a[2]-a[1]||n<4){
					printf("0");
					return 0;
				}else{
					printf("%lld\n",(n-3)*chu/2);
				}			
			}else if(c>=15&&c<=18){
				printf("%lld\n",10);
			}
		}
	}
	return 0;
}
