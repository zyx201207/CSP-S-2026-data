#include<bits/stdc++.h>
using namespace std;

int c,t;
long long n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long x=a[2]-a[1];
		long long num=(d/x)*2;
		if(n<num){
			printf("0\n");
			continue;
		}
		if(d/x==1||d/x==0){
			printf("0\n");
			continue;
		}
		printf("%lld\n",n-num+1);
	}
	return 0;
}
