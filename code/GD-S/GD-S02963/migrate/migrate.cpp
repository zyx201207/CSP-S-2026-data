#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000002],nxt[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		long long len=x[2]-x[1];
		d=d/len;
		if(d==1||d==0){
			printf("0\n");
			continue;
		}
		printf("%lld\n",max(n-d*2+1,0LL));
	}
	return 0;
}
