//遵义市新蒲新区滨湖中学 金卓承 GZ-S00294 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll r,l,mid,ans;
const ll N=2e6;
ll sum[N],a[N],n,m;
bool check(ll x){
	for(ll i=1+x;i<=n;i++){
		if((x)*a[i]-sum[i-1]+sum[i-x-1]<=m){
			//cout<<(i-x)*a[i]<<' '<<sum[i-1]+sum[i-x]<<' '<<x<<endl;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	r=n,l=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans+1;
	return 0;
}
