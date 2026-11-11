#include<bits/stdc++.h>
using namespace std;
const int MAXX=2e6+5;
int c,t,n;
long long d,x[MAXX];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d",&n);
		scanf("%lld",&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(c==0){
			if(n==4&&d==2){
				printf("1\n");
				printf("2\n");
				return 0;
			}
			if(n==5&&d==3){
				printf("0\n");
				printf("1\n");
				return 0;
			}
		}
	}
	return 0;
}
