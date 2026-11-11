#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int n, m, ans;
vector<char> s;
int p[N];
bool all_one = true;

void solve_all_one() {
	int l = 0, r = m - 1;
	while(l < r) {
		if(s[l] != s[r]) ans ++;
		l ++;
		r --;
	}
	cout << ans << '\n';
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		char ch;
		cin >> p[i] >> ch;
		if(p[i] != 1) all_one = false;
		for(int j = 1; j <= p[i]; j ++) 
			s.push_back(ch);
	}
	m = s.size();
	
	if(n <= 2) {
		if(n == 1) cout << 0 << '\n';
		else cout << min(p[1], p[2]) << '\n';
		return 0;
	}	
	if(all_one) {
		solve_all_one();
		return 0;
	}
	
	
	return 0;
}
