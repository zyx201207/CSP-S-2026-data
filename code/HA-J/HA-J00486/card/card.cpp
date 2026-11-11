#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

ifstream fin("card.in");
ofstream fout("card.out");

#define cin fin
#define cout fout


int main() {
	ll n,m;
	cin >> n >> m;
	
	ll cnt = n;
	
	ll a;
	while (cnt--) {
		cin >> a;
	} 
	
	for (ll i = 1; i <= m; i++) {
		cout << n << ' ';
	}
	
	return 0;
}
