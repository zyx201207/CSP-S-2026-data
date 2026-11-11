#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000002],k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		//ÌØÊâÐÔÖÊA
		if(n==1||n==2||n==3){
			printf("0\n");continue;
		}
		k=d/(x[2]-x[1]);
		if(k==0||k==1||n<2*k-1){
			printf("0\n");continue;
		}
		n=n-2*k+1;
		printf("%d",n);
	}
	return 0;
}
