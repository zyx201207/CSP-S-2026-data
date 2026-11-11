/*
好舒服好舒服啊

T1 直接切起嘛 
*/ 

#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 5e5 + 10;

void Freopen() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
}

int n;
ll m;
ll a[N], sum[N];

signed main() {
	Freopen();

	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for ( int i = 1; i <= n; i ++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for ( int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	
	int ptr = 1, ans = 1;
	for ( int i = 2; i <= n; i ++) {
		while (a[i] * (i - ptr) - (sum[i - 1] - sum[ptr - 1]) > m && ptr < n) ptr ++;
				
		ans = max(ans, i - ptr + 1);
	}
	
	cout << ans << '\n';

	return 0;
}

