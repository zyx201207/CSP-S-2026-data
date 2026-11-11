#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int n, l, r, ans;

int a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; i ++) 
		cin >> a[i] >> c[i];
	
	l = 1;
	r = n;
	
	while(l < r) {
		if(c[l] == c[r]) {
			int x = min(a[l], a[r]);
			a[l] -= x;
			a[r] -= x;
		}
		else {
			int x = min(a[l], a[r]);
			a[l] -= x;
			a[r] -= x;
			ans += x;
		}
		
		if(a[l] <= 0) l ++;
		if(a[r] <= 0) r --;
	}
	
	cout << ans;
	
	return 0;
}
