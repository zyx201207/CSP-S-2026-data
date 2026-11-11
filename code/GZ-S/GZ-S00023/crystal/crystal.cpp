//GZ-S00023 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],num[500010],ans=1,d[500010];
ll find(ll x,ll pos){
	ll low=pos,high=n,res=-1;
	while(high>=low){
		ll mid=(high+low)>>1;
		if(mid*a[mid]-num[mid]-((pos-1)*a[pos-1]-num[pos-1])-(pos-1)*(a[mid]-a[pos-1])<=x){
			res=mid;
			low=mid+1;
		}
		else high=mid-1;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;n>=i;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(ll i=1;n>=i;i++){
		num[i]=num[i-1]+a[i];
	}
	for(ll i=1;n>=i;i++){
		ans=max(ans,find(m,i)-i+1);
	}
	printf("%lld",ans);
	return 0;
}
