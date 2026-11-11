#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
typedef long long ll;

ll n,m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	sum[0] = 0;
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll mx = 0;
	for(int i = 1; i <= n; i++){
		ll l = 1,r = i;
		while(l < r){
			ll mid = (l + r) / 2;
			ll need = a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]);
			if(need <= m) r = mid;
			else l = mid + 1;
		}
		mx = max(mx,i - l + 1);
	}
	printf("%lld",mx);
	return 0;
}
