#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5;
ll n, m;

ll a[N + 5];
ll sum[N + 5];
ll sub[N + 5];
ll dp[N + 5];
ll maxn[N + 5];
ll x[N + 5];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	
		
	}
	sort(a + 1, a + n + 1);
	
	//Ç°×ººÍ
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	} 
	//²î·Ö
	
	for (int i = 2; i <= n; i++){
		sub[i] = sum[i] - sum[i - 1];
	} 
	
	dp[1] = 1;
	
	bool flaga = true;
	for (int i = 1; i <= n; i++){
		if (a[i] != i){
			flaga = false;
		}
	}
	if (flaga == true){
		for (int i = 1; i <= n; i++){
			if (sum[i] > m){
				cout << i << endl;
				return 0;
			}
		}
	}
	
	bool flagb = true;
	ll cha = a[2] - a[1];
	for (int i = 1; i <= n; i++){
		if (a[i] != a[i + 1] - cha){
			flagb = false;
		}
	}
	if (flagb == true){
		for (int i = 1; i <= n; i++){
			if (sum[i] > m){
				cout << i << endl;
				return 0;
			}
		}
	}
	
	ll ans= 0;
	for (ll i = 1; i <= n; i++){
		ll cur = a[i];
		ll cnt = 0;
		for (ll j = i; j >= 1; j--){
			if (cnt > m){
				
				maxn[i]--;
				break;
			}
			cnt += cur - a[j];
			maxn[i]++;
			if (cnt > m){
				
				maxn[i]--;
				break;
			}
		}
		
	}
	
	for (int i = 1; i <= n; i++){
		ans = max(ans, maxn[i]);
	}
	
	cout << ans << endl;
	return 0;
} 
