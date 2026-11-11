#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100010],b[100010],ans;
ll sumc(ll l,ll r){
	ll an=0,cnt=1;
	for(int i=l+1;i<=r;i++){
		an+=b[i]*(i-l);
	}
	return an;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	ll k;
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			k=sumc(i,j);
			if(k>m){
				ans=max(ans,j-i);
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
