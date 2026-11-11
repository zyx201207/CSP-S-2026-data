#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e7 +5;
ll a[maxn];
ll b[maxn];
int main(){
	freopen("crystal1.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	
	ll couple_1 = 0;
	ll couple_2 = 0;
	cin >> a[1] >> a[2];
	
	if(a[1] == a[2])couple_1 = a[1];
	couple_2 = a[2] - a[1];
	
	for(ll i = 3; i <= n; ++i){
		cin >> a[i];
		if(couple_1 != a[i])couple_1 = a[1] - 1;
		if(couple_2 != a[i] - a[i-1]) couple_2 = a[2] - a[1] -1;
	}
	if(couple_1 == a[1]){
		cout << n;
		return 0;
	}
	
	if(couple_2 == a[2] - a[1]){
		ll i = 0;
		ll min = 0;
		ll count = 0;
		while(1){
			min += i * couple_2;
			if(min > m)break;
			count++;
			i++;
		}
		cout << count;
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	
	int max = 0;
	for(ll i = 1; i <= n; ++i){
		ll min = 0;
		ll count = 0;
		for(ll j = 1; j <= i; ++j){
			b[j] = a[i] - a[j];
		}
		for(ll j = 1; j <= i; ++j){
			if(b[j] < 0) continue;
			min += b[j];
			if(min > m) break;
			count++;
		}
		if(max < count) max = count;
	}
	cout << max;
	return 0;
}
