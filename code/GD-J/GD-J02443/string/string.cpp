#include<bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 * 2 + 5;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a[maxn], ans = 0;
	char c[maxn];
	string s;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		for(int j = 0; j < a[i]; j++) s += c[i];
	}
	int l =  0, r = 0;
	for(int i = 0; i < s.size() / 2; i++) {
		l = i; r = n - i;
		if(!(s[l] == s[r])) {
			ans ++;
		}
	}
	cout << ans;
	return 0;
}

