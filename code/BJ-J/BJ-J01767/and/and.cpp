#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
string ll2s(ll x) {
	string res;
	while (x > 0) {
		res = char(x%2+'0')+res;
		x/=2;
	}
	return res;
}
ll s2ll(string s) {
	ll sum = 0;
	ll k = 1;
	for (int i = s.size()-1; i >= 0; i--) {
		sum += k*(s[i]-'0');
		k*=2;
	}
	return sum;
}
string s[200005];
bool val[200005];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	s[1] = ll2s(a[n]);
	int len = s[1].size();
	for (int i = n-1; i >= 1; i--) {
		string r = ll2s(a[i]);
		while (r.size() < len) {
			r = "0"+r;
		}
		s[n-i+1] = r;
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1; i <= n; i++) {
		val[i] = true;
	}
	string rss = "";
	for (int i = 0; i < len; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (val[j] && s[j][i]=='1') {
				sum++;
			}
		}
		if (sum >= m) {
			rss+="1";
			for (int j = 1; j <= n; j++) {
				if (val[j] && s[j][i]=='0') {
					val[j] = false;
				}
			}
		} else {
			rss+="0";
		}
	}
	cout << s2ll(rss) << endl;
	return 0;
}
