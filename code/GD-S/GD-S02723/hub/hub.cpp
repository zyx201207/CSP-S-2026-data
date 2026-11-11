#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[100003],v[100003];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&u[i],&v[i]);
		}
		n-=2*k;
		if(n%2!=0){
			n+=1;
			n/=2;
		}else{
			n/=2;
		}
		printf("%lld\n",n);
	}
}
