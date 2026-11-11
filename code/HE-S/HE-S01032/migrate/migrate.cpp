#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ll c,t;	
	ll n,d,a[100005]={};
	scanf("%lld %lld",&c,&t);
	for(int k=0;k<t;k++){
		ll ans=1,cnt=0;
		scanf("%lld %lld",&n,&d);
		for(int i=0;i<n;i++) scanf("%lld",a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
