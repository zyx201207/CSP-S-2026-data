#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
typedef long long ll;
ll a[N];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr) , cout.tie(nullptr);
	ll n , m;
	cin >> n >> m;
	cin >> a[1];
	ll maxa = 0 , cnt = a[1];
	maxa = max(maxa , a[1]);
	for(ll i = 2 ; i <= n ; i ++){
		cin >> a[i];
		maxa = max(maxa , a[i]);
		cnt = (cnt & a[i]);
	}
	if(m == 1){
		cout << maxa;
	}else if(m == n){
		cout << cnt;
	}else if(m == 2){
		maxa = 0;
		for(ll i = 1 ; i <= n ; i ++){
			for(ll j = 1 ; j <= n ; j ++){
				if((a[i] & a[j]) > maxa && i != j){
					maxa = (a[i] & a[j]);
				}
			}
		}
		cout << maxa;
	}
	return 0;
}
