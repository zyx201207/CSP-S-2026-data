#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, N, ans;
string str;
int main(){
//	/*
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	*/
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for(ll i = 1; i <= n; i++){
		ll x;
		char c;
		cin >> x >> c;
		N += x;
		for(ll i = 1; i <= x; i++){
			str += c;
		}
	}
	string n_str = str;
	reverse(n_str.begin(), n_str.end());
	for(ll i = 0; i < N; i++){
		if(str[i] != n_str[i]) ans++; 
	}
	cout << ans / 2;
	return 0;
}
//¹À·Ö£º68·Ö 
