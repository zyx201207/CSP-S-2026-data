#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n,m,a[N],s[N],ans,c[N];
bool check(ll mid){
	if (mid==1)
	    return true;
	for (int i = mid;i<=n;i++)
		if (c[i]-c[i-mid+1]-(i-mid)*(a[i]-a[i-mid+1])<=m)
		    return true;
	return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i = 2;i<=n;i++)
		s[i] = a[i]-a[i-1];
	for (int i = 2;i<=n;i++)
		c[i] = c[i-1]+(i-1)*s[i];
	ll l=1,r=n,mid;
	while (l<=r){
		mid = (l+r)>>1;
		if (check(mid)){
			l = mid+1;
			ans = mid;
		}
		else{
			r = mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}

