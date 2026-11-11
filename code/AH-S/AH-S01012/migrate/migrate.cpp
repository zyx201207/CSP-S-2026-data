#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long a[2000005],f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,t;
	scanf("%d%d",&cc,&t);
	while(t--){
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		//if(cc==11||cc==12){
			if(abs(a[2]-a[1])>=d)printf("0\n");
			else {
				long long ans=0,g=d/abs(a[2]-a[1]);
			//	for(int i=1;i<=g+1;i++)f[i]=0;
				printf("%lld\n",max(0ll,n-g*2+1));
			}
		//}
	} 
	return 0;
}
