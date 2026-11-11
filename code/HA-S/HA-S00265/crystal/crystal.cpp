#include<bits/stdc++.h>
using namespace std;
const long long _MAX = 5e5+5;
#define ll long long
#define ull unsigned long long

ll n , m , ans , a[_MAX] , b[_MAX];

bool cmp(ll a , ll b){
	return a < b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll l = 0 , r = 1;
	for (; r <= n ; r ++){
		while (m < (r-l-1)*a[r]-(b[r-1]-b[l-1])) l ++;
		ans = max(ans , r - l);
		b[r] = b[r-1]+a[r];
	}
	cout << ans;
	return 0;
}
