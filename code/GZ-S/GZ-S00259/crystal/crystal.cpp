//GZ-S00259, 孟杰锐, 贵阳第一实验中学
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long n, m, cnt, sumn, cnt1;
int a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i) cnt++;
	}
	
	sort(a+1, a+1+n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (sumn > m) {
				cout << cnt1;
				return 0;
			}
			sumn = sumn + (a[i] - a[j]);
			cnt1++;
		}
	}
	
	return 0;
} 
