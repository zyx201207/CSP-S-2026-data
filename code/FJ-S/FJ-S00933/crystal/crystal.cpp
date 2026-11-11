#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MAXN = 5e5 + 5;
long long n,m;
long long a[MAXN],b[MAXN];

long long find(ll t,ll k) {
	//查找b[l] ~ b[r]最左边<=t的数
	ll kk = -1,l = 1,r = n;
	while(l < r) {
		ll mid = (l + r) >> 1,cnt = b[mid] - (k - mid) * (a[n] - a[k]) - b[k];
		if(cnt > t)      l = mid + 1;
		else if(cnt < t) r = mid - 1;
		else {
			kk = mid;
			break;
		} 
	} 
	if(kk == -1) return l;
	while(kk > 1 && b[kk - 1] == b[k]) kk--;
	return kk;
}

long long findd(ll t,ll k) {
	for(ll i = 1;i <= n;i++) if(b[i] - (k - i) * (a[n] - a[k]) - b[k] <= t) return i; 
}

int main() {
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i++) scanf("%lld",&a[i]);
	
	sort(a + 1,a + n + 1);
	
	for(ll i = 1;i <= n;i++) b[i] = a[i] - a[i - 1];
	for(ll i = n - 1;i >= 1;i--) b[i] += b[i + 1];
	for(ll i = n - 1;i >= 1;i--) b[i] += b[i + 1];
	for(ll i = 1;i <= n;i++) swap(b[i],b[i - 1]);
	
//	for(ll i = 1;i <= n;i++) cout << b[i] << ' ';
//	cout << '\n'; 
	
	ll ans = 1;
	for(ll i = n;i >= 1;i--) ans = max(i - find(m,i) + 1,ans);
	
	printf("%lld",ans);
	
	
} 
