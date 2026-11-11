#include <bits/stdc++.h>

using namespace std;
using ll = long long; 

ifstream fin("string.in");
ofstream fout("string.out");

#define cin fin
#define cout fout

int main() {
	ll n;
	cin >> n;
	 
	string str;
	
	ll way = 0;
	ll a;
	char c;
	for (ll i = 0; i < n; i++) {
		cin >> a >> c;
		way += a;
		string s;
		for (ll j = 0; j < a; j++) s += c;
		str = str + s;
	}
	
	ll l = 0,r = way - 1,ans = 0;
	
	while (l <= r) {
		if (str[l++] != str[r--]) ans++;
	}
	
	cout << ans;
	return 0;
}
