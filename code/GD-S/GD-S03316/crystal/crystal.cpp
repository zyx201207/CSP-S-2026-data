#include <bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , sum[500005] , ans;
long long er_fen (long long l , long long r , long long mx){
	if (l >= r)  return l;
	long long mid = (l + r) >> 1;
	long long siz = (mx - mid + 1) * a[mx] - (sum[mx] - sum[l - 1]);
	if (siz <= m)  r = mid;
	else  l = mid + 1;
	return er_fen (l , r , mx);
}
int main (){
	freopen ("crystal.in" , "r" , stdin);
	freopen ("crystal.out" , "w" , stdout);
	cin.tie (0) -> sync_with_stdio (0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)  cin >> a[i];
	sort (a + 1 , a + n + 1);
	for (int i = 1 ; i <= n ; i++){
		sum[i] = sum[i - 1] + a[i];
		ans = max (ans , i - er_fen (1 , i , i) + 1);
	}
	cout << ans;
	return 0;
}
