#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],m,n,maxn,d;
void solve(){
	ll sum=0,cnt=1;
	for(ll i=2;i<=n;i++){
		ll dlt=d*(i-1);
		if(sum+dlt<=m){
			sum+=dlt;
			cnt++;
		}
	}
	printf("%lld",cnt);
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	bool ok=1;
	d=a[2]-a[1];
	for(ll i=2;i<n;i++){
		if(a[i]+d!=a[i+1]){
			ok=0;
			break;
		}
	}
	if(ok){
		solve();
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ll sum=0,cnt=1;
		for(ll j=i-1;j>=1;j--){
			ll dlt=a[i]-a[j];
			if(sum+dlt<=m){
				sum+=dlt;
				cnt++;
			}
		}
		maxn=max(maxn,cnt);
	}
	printf("%lld",maxn);
	return 0;
}
