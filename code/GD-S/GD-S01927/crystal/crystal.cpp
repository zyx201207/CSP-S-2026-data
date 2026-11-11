#include <bits/stdc++.h> 
using namespace std;
#define int long long

const int N = 5e3 + 10;
int n, m, ans;
int a[N];
bool same_d = true;
int d;

void solve_same_d() {
	int i = 0;
	while(true) {
		m -= i * d * 2;
		ans += 2;
		i ++;
		if(m <= (i + 1) * d * 2 || i >= (n + !(n & 1)) / 2) {
			ans += (m >= (i + 1) * d);
			break;
		}
	}
	cout << ans - !(n & 1) << '\n'; 
}

signed main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1] >> a[2];
	d = a[2] - a[1];
	for(int i = 3; i <= n; i ++) {
		cin >> a[i];
		if(a[i] - a[i - 1] != d) same_d = false;		 
	}			
	sort(a + 1, a + n + 1);
	
	if(same_d) {
		solve_same_d();
		return 0;
	}

	return 0;
}
