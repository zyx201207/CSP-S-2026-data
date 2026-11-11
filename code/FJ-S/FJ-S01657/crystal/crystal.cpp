#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	sort(a + 1,a + n + 1);
	long long gc = a[2] - a[1];
	for (int i = 1; i <= n; i++) {
		sum += gc * (i - 1);
		if(sum > m) {
			cout << i - 1;
			return 0;
		}                   
	}
	cout << n; 
	return 0;
}

