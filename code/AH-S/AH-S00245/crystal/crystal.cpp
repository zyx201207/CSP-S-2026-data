#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , a[500005] , d[500005], cnt = 0 , maxn , m;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	for(ll i = 1 ; i <= n ; i++) d[i] = a[i] - a[i - 1];
	ll midpos = n / 2 + 1;
	ll lz = midpos - 1 , rz = midpos + 1;
	while(m >= a[midpos] - a[lz] && lz >= 0) d[lz + 1] = 0 , d[lz] += a[midpos] - a[lz] , lz-- , m -= a[lz];
	while(m >= (a[rz] - a[lz]) * (rz - lz + 1)) d[lz] += a[rz] - a[lz] , d[rz + 1] -= a[rz] - a[lz], m -= (a[rz] - a[lz]) * (rz - lz + 1) , rz++;
	d[0] = -1e18;
	for(ll i = 1 ; i <= n ; i++){
		cnt = (d[i] == 0) ? cnt + 1 : 1;
		maxn = max(maxn , cnt);
	}
	cout << maxn - 1;
	return 0;
}
