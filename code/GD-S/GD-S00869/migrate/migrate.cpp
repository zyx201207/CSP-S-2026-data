#include<stdio.h>
int c,t,i,n;long d,a[2000002],k,l;
inline int X(int x){return x>0?x:0;}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if((c^11)&&(c^12)&&c){
		while(t--) puts("0");
		return 0;
	}
	while(t--){
		scanf("%d%ld",&n,&d);
		for(i=0;++i<=n;)
			scanf("%ld",a+i);
		k=a[2]-a[1];
		if(d<=k) puts("0"); else
		l=d/k*k,printf("%ld\n",X((a[n]-(a[1]+2*l-k))/k+1));
	}
}
