#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e5 + 10;
const int M = 2e3 + 10;
int n, m;
ll ans, f[M][M], a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	
	ll Sum = a[1];
	for(ll i = 2; i <= n; i++)
		Sum &= a[i];
	if(m == n){
		printf("%lld\n", Sum);
		return 0;
	}
	if(m == 1){
		ll Max = 0;
		for(ll i = 1; i <= n; i++)
			Max = max(Max, a[i]);
		printf("%lld\n", Max);
		return 0;
	}
	if(m == 2){
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				if(i != j){
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	if(m == n - 1){
		Sum = a[1];
		for(ll i = 2; i <= n; i++)
			Sum &= a[i];
		for(ll i = 1; i <= n; i++){
			ll x = Sum;
			x ^= a[i];
			ans = max(ans, x);
		}
		printf("%lld\n", ans);
		
		return 0;
	}
	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= n; j++){
			if(i == 1){
				f[i][j] = a[j];
			}else{
				f[i][j] = max(f[i - 1][j], f[i - 1][j] & a[j]);
			}
		}
	}
	printf("%lld\n", f[m][n]);
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
