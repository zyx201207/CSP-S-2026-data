#include <bits/stdc++.h>
#define endl '\n'
#define fn "string"
typedef long long ll;
using namespace std;
ll n;
string s;
int main(){
	freopen(fn ".in", "r", stdin);
	freopen(fn ".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin >> n;
	for (int i = 1; i <= n; i ++){
		int ai;
		char c;
		cin >> ai >> c;
		for (int j = 1; j <= ai; j ++){
			s += c;
		}
	}
	ll l = 0,r = s.size() - 1, ans = 0;
	while (l <= r){
		if (s[l] != s[r]) ans ++;
		l ++, r --;
	}
	cout << ans;
	return 0;
}
