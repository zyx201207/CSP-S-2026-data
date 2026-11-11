#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+4;
ll n,m;
ll a[N];
bool check(ll x){
	ll final=x;
	for(ll i=final;final<=n;final++){
		ll sum=0,flag=0;
		for(ll j=final-x+1;j<=final-1;j++){
			sum+=a[final]-a[j];
			if(sum>m)break;
		}
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	} 
	printf("%lld",l);
}
/*考虑二分答案
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
15:17 通过前三个大样例
望舒高悬任风过,
枯树梨花不染墨.
许诺,如雪落.
随风之爱皆罪恶. 
*/
