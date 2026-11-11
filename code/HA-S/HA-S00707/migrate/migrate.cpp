#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,ans=0;
long long m,a[N],k,b[N],d;
int p=0,i,j,c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(m>a[2]-a[1]&&m/(a[2]-a[1])*2+1<=n){
			k=m/(a[2]-a[1]);
			k=k*2-1;
			k=n-k;
			printf("%lld\n",k);
		}else printf("0\n");
	}
	return 0;
}
