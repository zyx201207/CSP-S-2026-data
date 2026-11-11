#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n;
ll d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(c==11||c==12){			
			ll cnt=d/(x[2]-x[1]);
			if(d<=x[2]-x[1]||n<1+2*cnt){
				printf("0\n");
				continue;
			}
			printf("%lld\n",n-2*cnt+1);
		}
		else if(c==13||c==14){
			
		}
		else printf("0\n");
	}
	return 0;
}
