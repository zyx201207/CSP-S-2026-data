#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (ll i = 1;i <= n;++i){
		cin >> a >> c;
		for (int j = 1;j <= a;++j){
			s.push_back(c);
		}
	}
	ll b,k = 0;
	if (s.size() % 2 == 1){
		b = s.size() / 2 + 1;
	} else {
		b = s.size() / 2;
	}
	for (int i = b;i < s.size();++i){
		if (s[i] != s[s.size()-i-1]){
			++k;
		}
	}
	cout << k;
	return 0; 
}
