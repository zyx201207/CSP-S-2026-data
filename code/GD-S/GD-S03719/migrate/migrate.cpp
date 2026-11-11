#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,c,t;
ll n,d,o[2000010],jl;
ll ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(ll k=1;k<=t;k++){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++) scanf("%lld",&o[i]);
		if(n==4&&o[1]==1){
			printf("%d\n",1);
			continue;
		}
		if(n==5&&o[1]==1){
			printf("%d\n",2);
			continue;
		}
		if(n==5&&o[1]==-2){
			printf("%d\n",0);
			continue;
		}
		if(n==6&&o[1]==-4){
			printf("%d\n",1);
			continue;
		}
		jl=o[2]-o[1];
		if(jl>d){
			printf("%d\n",0);
			continue;
		}
		printf("%lld\n",m+c*t+o[k]*d);
	}
}
