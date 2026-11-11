#include<bits/stdc++.h>

using namespace std;

int n;
string all;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	long long ans = 0;
	long long l = 0, r = 0;
	for(int i = 0; i < n; i++) {
		int k;
		char c;
		cin >> k >> c;
		string sub(k, c);
		all += sub;
		r += k;
	}
	r--;
	while(l <= r) {
		if(all[l] != all[r]) ans++;
		l++;
		r--;
	}
	cout << ans;
	
	return 0;
}
