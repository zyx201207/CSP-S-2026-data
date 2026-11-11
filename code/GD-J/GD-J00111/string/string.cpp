#include <bits/stdc++.h>
#define ll size_t
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	string s = "";
	while (n--){
		int a; char c;
		cin >> a >> c;
		while (a--) s += c;  
	} 
	ll ans = 0; 
	for (ll i = 0;i < s.size() / 2; i++) 
		if ( s[i] != s[s.size() - i - 1]) ans++ ;
	
	cout << ans;
	return 0;
} 
