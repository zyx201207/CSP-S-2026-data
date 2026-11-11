#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200001],maxx = LLONG_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (ll k = m;k <= n;k++){
		ll ans = a[k];
		for (ll i = k - 1,j = 2;j <= m;i--,j++) ans &= a[i];
		maxx = max(maxx,ans);
	}
	
	cout << maxx;
	return 0;
}
