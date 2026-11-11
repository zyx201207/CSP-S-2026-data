#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , a[200005] , ans , x = pow(2 , 31) - 1 , maxn = -1e18; 
void dfs(ll st , ll xxx , ll chosed){
	if(chosed == m){
		ans = max(ans , xxx);
		return ;
	}
	if(st >= n) return ;
	for(ll i = st + 1 ; i <= n ; i++) dfs(i , xxx & a[i] , chosed + 1);
	dfs(st + 1 , xxx , chosed);
	return ;
}
bool check(ll a){
	while(a != 1){
		if(a % 2 == 0) a /= 2;
		else return 0;
	}
	return 1;
}
bool speaciala = 1;
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++){
		cin >> a[i];
		x &= a[i];
		maxn = max(maxn , a[i]);
		if(!(check(a[i] + 1))) speaciala = 0;
	}
	if(m == n) cout << x; // c7 solved5p
	else if(m == 1) cout << maxn; //c6 solved5p
	else if(m == 2){ // c8~10 solved 15p get
		ll maxx = 0;
		for(ll i = 1 ; i <= n ; i++) for(ll j = i + 1 ; j <= n ; j++) maxx = max(maxx , (a[i] & a[j]));
		cout << maxx;
	} else if(m == n - 1){ // c11~12 solved10p
		ll maxt = 0;
		for(ll i = 1 ; i <= n ; i++){
			ll t = pow(2 , 31) - 1;
			for(ll j = 1 ; j <= n ; j++) if(j != i) t &= a[j];
			maxt = max(maxt , t);
		}
		cout << maxt;
	}else if(n <= 20){ // c1~5 solved25p
		dfs(0 , pow(2 , 31) - 1 , 0);
		cout << ans;
	}else if(speaciala){ // c13(special stituation A) solved5p
		sort(a + 1 , a + 1 + n);
		cout << a[n - m + 1];
	}else{
		sort(a + 1 , a + 1 + n);
		for(ll i = n ; i >= 1 ; i--) ans &= a[i];
		cout << ans;
	}
	return 0;
}
