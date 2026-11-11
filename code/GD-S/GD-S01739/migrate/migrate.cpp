#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+7;
const ll MX=1e18+1;
ll c,t,n,d,r,l;
ll x[N];
bool ch(int i){
	if((x[i+2]-x[i]<=d)&&(x[i+3]-x[i]>d)&&(x[i+3]-x[i+1]<=d)&&((i+4>n)||(x[i+4]-x[i+1]>d)))return 1;
	return 0;
}
bool chr(int i){
	if(((x[i]-x[i-1]<=d)&&(x[i]-x[i-2]>d)&&(x[i+1]-x[i-1]>d))||(i==2&&(x[i+1]-x[i-1]>d)))return 1;
	return 0;
}
bool chl(int i){
	if(((x[i+1]-x[i]<=d)&&(x[i+2]-x[i]>d)&&(x[i+1]-x[i-1]>d))||(i==n-1&&(x[i+1]-x[i-1]>d)))return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll t=1;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]); 
		}
		for(int i=n+1;i<=n+10;i++){
			x[i]=MX;
		}
		if(n<4){
			printf("0\n");
			continue;
		}ll ans=0;
		for(int i=1;i<=n-3;i++){
			if(ch(i)){
				r=i,l=i+3;
				while(chr(r))r--;
				while(chl(l))l++;
				ans+=(i-r+1)*(l-i-3+1);
			}
		}printf("%lld\n",ans);
	}
	return 0;
}
