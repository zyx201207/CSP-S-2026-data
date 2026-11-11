#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
ll n,m,a[N],s[N],ans=1,tot;

ll check(ll j,ll i){
	ll k=i-j;
	if (k*a[i]-s[i-1]+s[j-1]<=m) return 1;
	else return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=1;i<=n;i++){
		ll l=1,r=i-1;
		while (l<r){
			ll mid=l+r>>1;
//			printf("orz:%lld %lld %lld %lld\n",l,r,mid,check(mid,i));
			if (check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
