#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long c,t,n,m,a[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(c==11||c==12){
			if(n<=2||m<(a[2]-a[1])*2) printf("0\n");
			else{
				d=a[2]-a[1];
				printf("%lld\n",max(0ll,n-(m/d*2-1)));
			}
		}else if(c==13||c==14) printf("0\n");
	}
		
	return 0;
}
