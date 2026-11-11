#include<bits/stdc++.h>
using namespace std;

#define N 200007

int n, m;
int a[N];
bitset<N> c;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 30; i >= 0; i--) {
		int d = 0;
		for(int j = 1; j <= n; j++) if((a[j] & (1ll << i)) && c[j] == 0) d++;
		if(d >= m) {
			ans += (1 << i);
			for(int j = 1; j <= n; j++) if(!(a[j] & (1ll << i))) c[j] = 1;
		}
	}
	cout << ans << "\n";
	
	return 0;
} 
