#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ri=5e5+5;
ll n,m,a[ri],pre[ri],pre2[ri],sum,c[ri];

bool check(int x){
	if(x==1) return true;
	ll l=1,r=x,sum;
    ll minn=1e18;
	for(int i=0;x+i<=n;i++){
		sum=(x-1)*pre[x+i]-(pre2[x+i-1]-pre2[i]);
		minn=min(minn,sum);
		if(minn<=m) return 1;
	}
	return minn<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i]-a[i-1];
		pre2[i]=pre2[i-1]+pre[i];
		c[i-1]=a[i]-a[i-1];
	}
	ll l=1,r=n,ans=1;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
/*
¸øÎÒÂú·Ö°¡°¡°¡°¡°¡
*/ 
