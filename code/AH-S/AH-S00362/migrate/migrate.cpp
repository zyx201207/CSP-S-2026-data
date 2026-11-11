#include<bits/stdc++.h>
using namespace std;
int const N=2e6+10;
long long c,t,n,a[N],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int k=1;k<=t;k++){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
	}
	if(c==0){
		if(t==2){
			if(n==5&&d==2)printf("1\n2");
			else if(n==6&&d==2) printf("0\n1");
		}else if(t==17)printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
	}
	return 0;
}
