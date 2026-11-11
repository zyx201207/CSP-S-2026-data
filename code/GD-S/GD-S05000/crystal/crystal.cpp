#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
ll n,m;
ll check(const ll& pl){
	ll mm=m,aans=1,k=pl-1;
	while((mm-(a[pl]-a[k])>=0)&&k>=1){//mm>=0&&k>=0
		aans++;
		mm=mm-(a[pl]-a[k]);
		k--;
	}
	return aans;

}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	//cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//cin>>a[i];
	}
	ll ans=0;
	sort(a+1,a+1+n);
	for(ll anss,i=1;i<=n;i++){
		ans=max(ans,check(i));
	}
	printf("%lld",ans);
	//cout<<ans;
	return 0;
}
