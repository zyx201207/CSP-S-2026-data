#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long maxa;
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		maxa=x[2]-x[1];
		
		if(d==1||d<=maxa){
			printf("0\n");
			continue;
		}
		printf("%d\n",max(1ll*0,n-(2*(d/maxa)-1)));
	}
	return 0;
}
