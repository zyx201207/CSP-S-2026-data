#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , ans = 1;

bool cmp(long long a , long long b) {
	return a > b;
}

bool cmpa() {
	for(long long i = 1;i <= n;i++) 
		if(a[i] != i) {
			return false;
		}
	}
	return true;
}

bool cmpb() {
	long long x = a[1] - a[2];
	for(long long i = 2;i < n;i++) {
		if(a[i] - a[i + 1] != x) {
			return false;
		}
	} 
	return true;
}

void solvea() {
	long long mid = n / 2;
	long long num = m;
	long long ans = 1;
	for(long long i = 1;i <= n / 2;i++) {
		if(mid - i >= 1 && num - i >= 0) {
			num -= i;
			ans++;
		}
		if(mid + i >= 1 && num - i >= 0) {
			num -= i;
			ans++;
		}
	}
	cout << ans;
	return;
}

void solveb() {
	long long x = abs(a[1] - a[2]);
	long long mid = n / 2;
	long long num = m;
	long long ans = 1;
	for(long long i = 1;i <= n / 2;i++) {
		if(mid - i >= 1 && num - i * x >= 0) {
			num -= i * x;
			ans++;
		}
		if(mid + i <= n && num - i * x >= 0) {
			num -= i * x;
			ans++;
		}
	}
	cout << ans;
	return;
}

int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	if(cmpa()) {
		solvea();
	}
	else if(cmpb()) {
		solveb();
	}
	else {
		sort(a + 1 , a + 1 + n , cmp);
		for(long long i = 1;i <= n;i++) {
			long long x = m;
			long long maxn = 1;
			for(long long j = i + 1;j <= n;j++) {
				if(abs(a[j] - a[i]) <= x) {
					x -= abs(a[j] - a[i]);
					maxn ++;
				}
			}
			ans = max(ans , maxn);
		}
		cout << ans << endl;
	}
	return 0;
} 
