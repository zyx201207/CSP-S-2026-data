#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1000000],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll cnt=1;
		ll t=m;
		for(ll j=i+1;j<=n;j++){
			if(a[j]-a[j-1]<=t){
				cnt++;
				t-=a[j]-a[j-1];
				a[j-1]=a[j];
			}else{
				ans=max(ans,cnt);
				break;
			}
		}
	}
	if(ans==1){
		ans=0;
	}
	printf("%lld",ans);
	return 0;
} 
