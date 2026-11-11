#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[200010],ans = 0;
bool b[200010][35];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}sort(a + 1,a + n + 1);
	ll ma = a[n];
	
	
	
	
	if (n == m){
		ll t = a[1];
		for(ll i = 2;i <= n;i++){
		 	t = t & a[i];
		}cout << t;
		return 0;
	}if (m == 1){
		ll t = a[1];
		for(ll i = 2;i <= n;i++){
		 	if (a[i] > t) t = a[i];
		}cout << t;
		return 0;
	}
	ll mm = 1;
	while (mm <= ma){
		mm *= 2;
	}mm /= 2;
	ll s = 0;
	ll sm = mm * 2;
	ll x = 1;
	for(ll i = n;i >= x;i--){
		if (a[i] % sm >= mm){
			s++;
		}else{
			cout << s << endl; 
			if (s == 2){
				cout << ll(a[i - 1] & a[i - 2]);
				break;
			}else if (s >= 2){
				sm /= 2;
				mm /= 2;
				s = 0;
				i = n;
				x = n - s + 1;
			}else{
				sm /= 2;
				mm /= 2;
				s = 0;
			}
		}
	}
	
	return 0;
}
