#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5*1e5+10;
ll s[maxn],a[maxn],n,m,ans=1;
ll ss[maxn];
bool checka(ll left,ll right){
	return m>=ss[left]-ss[right]-(right-left)*s[right];
}
ll erfen(ll target){
	ll l=1,r=target,anss=1;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(checka(mid,target)){
			anss=max(anss,target-mid+1);
			r=mid-1;
		}else l=mid+1;
	}
	return anss;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	s[n]=0;
	for(ll i=n-1;i>=1;i--){
		s[i]=s[i+1]+a[i+1]-a[i];
	}
	ss[n]=0;
	for(ll i=n-1;i>=1;i--){
		ss[i]=ss[i+1]+s[i];
	}
		
	for(ll i=1;i<=n;i++){
		ans=max(ans,erfen(i));
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
