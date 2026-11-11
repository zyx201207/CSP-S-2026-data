#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxn = -1, sum = 1;
	cin >> n >> m;
	for(int i=1; i<=n+1; i++) {
		cin >> a[i];
	}
	if(m == n) {
		for(int i = 1; i<=n; i++) {
			sum &= a[i];
		}
		cout << sum;
		return 0;
	}
	else {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i != j)
				maxn = max((a[i] & a[j]), maxn);
			}	
		}
		cout << maxn;
		return 0;
	}
	
}
