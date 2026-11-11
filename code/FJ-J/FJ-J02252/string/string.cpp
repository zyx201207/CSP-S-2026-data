#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
ll n, len;
ll ans;
string s;
ll a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	while (n--) {
		ll a;
		char c;
		cin >> a >> c;
		len += a;
		s += string(a, c);
	}
	cout << s << "\n";
	for (int i = 0;i < len / 2;i++) {
		if(s[i] != s[len - i - 1]) {/*cout << i << " ";*/ans++;}
	}
	cout << ans;
	return 0;
}
