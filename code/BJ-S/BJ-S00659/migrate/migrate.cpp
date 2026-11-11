#include<iostream>
#include<cstdio>
#include<vector>
using namespace std ;
int main(){
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	int c ,t ;
	scanf("%d%d",&c,&t) ;
	while(t--){
		int n , d ;
		scanf("%d%d",&n,&d) ;
		long long a1 , a2;
		scanf("%lld%lld",&a1,&a2) ;
		int cc ;
		for(int i = 2 ; i < n ; i++) scanf("%d",&cc) ;
		long long ch = a2 - a1 ;
	if((n-(d/ch+1)+1)*(d/ch-2)>0)printf("%lld",(n-(d/ch+1)+1)*(d/ch-2)) ;
	else printf("0\n") ;
	}
	return 0 ;
}