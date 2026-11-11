#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll ans=a[1];
	for(ll i=2;i<=m;i++){
		if(ans&a[i]==0){
			m++;
			continue;
		}
		ans&=a[i];
	}
	printf("%lld",ans);
	return 0;
}
