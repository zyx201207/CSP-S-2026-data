#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int sum = 0;
	if(m == 1) {
		for(int i = 1; i <= n; i++)
			sum = max(sum, a[i]);
		cout << sum;
	}
	int ans = 1;
	if(m == n) {
		for (int i = 1; i <= n; i++)
			ans &= a[i];
		cout << ans;
	}
	if(m == 2) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				sum = max(sum, a[i] & a[j]);
		cout << sum;
	}
	return 0;	
}

