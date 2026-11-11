#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	string s;
	while(n--){
		ll a;
		char c;
		cin >> a >> c;
		while(a--)s += c;
	} 
	ll len = s.size();
	ll cnt = 0;
	for(int i = 0;i < len / 2;i++){
		if(s[i] != s[len - i - 1])cnt++;
	}
	cout << cnt;
	return 0;
}
