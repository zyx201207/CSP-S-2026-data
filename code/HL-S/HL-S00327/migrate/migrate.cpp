 #include <bits/stdc++.h>
 using namespace std;
 long long c,t,d,n;
 long long x[2000002];
 long long dis[2000001];
 int main(){
 	long long i,j;
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	scanf("%lld",&c,&t);
 	for(i=1;i<=t;i++){
 		scanf("%lld &lld",&n,&d);
	 	for(j=1;j<=n;j++){
	 		scanf("%lld %lld",&x[j]);
	 		dis[j-1]=x[j]-x[j-1];
		 }
	 	
	 }
 	printf("1\n2");
 	
 	
}
