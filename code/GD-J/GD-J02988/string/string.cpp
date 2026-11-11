#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 200005;
int n, a[MAXN];
char c[MAXN];
ll m;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		m += a[i]; 
	}
	ll ans = 0;
	int l = 1, r = n;
	ll rstl = a[1], rstr = a[n];
	while(l < r){
		if(c[l] != c[r]){
			ans += min(rstl, rstr);
		}
		ll tmp = min(rstl, rstr);
		rstl -= tmp, rstr -= tmp;
		if(rstl == 0){
			l++;
			rstl += a[l];
		}
		else if(rstr == 0){
			r--;
			rstr += a[r];
		}
	}
	cout << ans;
//	cout << ' ' << m;
	return 0;
}
