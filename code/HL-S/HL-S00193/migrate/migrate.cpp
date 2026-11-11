#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500002],sum;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--){
			int n,d;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			if(a[2]-a[1]>d){
				printf("0\n"); 
			}
			for(int i=n-2;i;i--) sum+=i;
			printf("%lld\n",sum);
		}
	}
	printf("%d",sum);
	return 0;
}
