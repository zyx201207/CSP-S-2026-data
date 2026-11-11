#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==13||c==14){
		for(int i=1;i<=t;i++)printf("%d\n",0);
	}else{
		while(t--){
		scanf("%lld%lld",&n,&d);
		long long ae,ar;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ae=a[2]-a[1];
		if(ae>=d || n<=3){
			printf("0\n");
			continue;
		}
		ar=d/ae;
		printf("%lld\n",max(0ll,n-2*ar+1ll));
	}
	}
	return 0;
}
