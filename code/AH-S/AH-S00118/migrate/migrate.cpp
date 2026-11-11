#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e7 + 5;
ll a[maxn];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for(int i = 1; i <= t; t++){
		ll n, d;
		cin >> n >> d;
		cin >> a[1] >> a[2];
		int couple = a[2] - a[1];
		for(int j = 3; j <= n; ++j){
			cin >> a[j];
			if(a[i] - a[i - 1] != couple) couple -= 1;
		}
		if(couple == a[2] - a[1]){
			cout << n / d / couple + 1;
		}
		
	}
	return 0;
}
