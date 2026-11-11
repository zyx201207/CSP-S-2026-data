#include <bits/stdc++.h>
#define ll long long
const ll N = 5e5 + 5;
using namespace std;
ll n, m, ans;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++){
		m -= abs(abs(a[i]) - abs(a[i - 1]));
		if (m <= 0) break;
		ans++;
	}
	cout << ans;
	return 0;
}
/*

*/
