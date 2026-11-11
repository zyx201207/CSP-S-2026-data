#include<bits/stdc++.h>
using namespace std;

#define N 200007

int n;
int a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int i = 1, j = n;
	long long ans = 0;
	while(i < j) {
		int d = min(a[i], a[j]);
		if(c[i] != c[j]) ans += d;
		a[i] -= d;
		a[j] -= d;
		if(a[i] == 0) i++;
		if(a[j] == 0) j--;
		
	}
	cout << ans << "\n";
	
	return 0;
} 
