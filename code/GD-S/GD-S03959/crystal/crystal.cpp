#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long 
const int N = 5e5 + 5;
ll m;
int n;
ll a[N], c[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i>0){
			c[i] = a[i] - a[i-1];
		}
	} 
	ll cnt = 0, ans;
	for(int i = 1; i < n; i++){
		ll l = m;
		ans = 1;
		ll r = 1;
		for(int j = i; j < n; j++){
			l -= r * c[j];
			r++; 
			if(l>=0) ans++;
			else break;
		}
		cnt = max(cnt, ans);
	}  
	cout << cnt << endl;
	return 0;
}
