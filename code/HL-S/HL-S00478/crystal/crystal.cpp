#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A = 5e5 + 5;
ll n , m , a[A] ,ans , sum[A];
bool cmp(ll a , ll b){
	return a < b;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	
	for(int i = 1;i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i ++)
	sum[i] = (a[i] + sum[i - 1]);
	bool flaga = 1 , flagb = 1;
	for(int i = 1;i <= n;i ++){
		if(a[i] != i) flaga = 0;
		if(i != 1 && i != n&& a[i] - a[i-1] != a[i + 1] - a[i]) flagb = 0;
	}
	if(flaga){
		ll tmp = m;
		for(int i = n;i >= 1;i --){
			if(tmp >= (n - i)) tmp -=(n - i) , ans ++;
		}
		cout << ans;
		return 0;
	}
	if(flagb){
		ll tmp = m , jian = a[n] - a[n-1] , ans = 1;
		for(int i = jian;tmp >= i;i+=jian) ans++ , tmp-=i;
		cout << ans;
		return 0;
	}
	for(ll i = 1;i <= n;i ++){
		for(ll j = 1;j < i;j ++){
			ll tmp = a[i] * (i - j);
			ll res = tmp - (sum[i - 1] - sum[j - 1]);
			if(res <= m) ans = max(ans , i - j + 1);
		}
	}
	cout << ans;
	return 0;
}