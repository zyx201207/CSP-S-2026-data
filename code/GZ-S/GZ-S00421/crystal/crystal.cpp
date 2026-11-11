//GZ-S00421 遵义第十二中学 陈俊熙 
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n, m, d;
int a[N];

bool check(int x) {
	long long r = d * x * x + d * x;
	return r <= m * 2;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	d = a[2] - a[1];
	
	int l = 0, r = m / 2;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		
		if (check(mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	cout << l + 1;
	return 0; 
}
