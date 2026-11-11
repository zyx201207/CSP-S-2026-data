#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,id,sum;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	string s;
	for (ll i = 1;i <= n;i++){
		cin >> a >> c;
		for (ll j = 1;j <= a;j++) s += c;
	}
	string t = s;
	reverse(t.begin(),t.end());
	if (t == s){
		cout << 0;
		return 0;
	}
	ll mid = s.size() / 2,cnt = 0;
	if (s.size() & 1) mid++;
	for (ll i = 0;i < s.size();i++){
		if (i + 1 > mid){
			if (s.size() & 1) if (s[mid * 2 - i - 2] != s[i]) cnt++;
			else if (s[mid * 2 - i - 1] != s[i]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
