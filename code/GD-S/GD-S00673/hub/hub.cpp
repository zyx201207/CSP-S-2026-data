#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=1e6;
ll c,t,n,k,u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&k);
		for(ll i = 1;i<n;i++) scanf("%lld %lld",&u[i],&v[i]);
		printf("%lld\n",k-1);
	}	
	return 0;
}

