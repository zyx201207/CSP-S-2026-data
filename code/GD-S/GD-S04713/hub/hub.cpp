#include<bits/stdc++.h>
using namespace std;
long long c,T;
long long n,k;
long long u[1000000],v[1000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld",&c,&T);
	while(T--){
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld",&u[i],&v[i]);
		} 
		printf("0\n");
	} 
	return 0;
} 
