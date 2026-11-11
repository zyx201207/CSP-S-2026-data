#include<bits/stdc++.h> 
using namespace std;
const int N=10000005;
long long c,n,m,d,p;
long long w[N],k1[N],k2[N]; 
long long travel[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	long long num;
	scanf("%lld",&num);
	for(int i=1;i<=n;i++) scanf("%lld",&k1[i]);
	while(p--){
		for(int i=1;i<=p;i++) scanf("%lld",&w[i]);
	}
	printf("%ld",w[1]+k1[1]+k2[1]+travel[1]);
	return 0;
} 
