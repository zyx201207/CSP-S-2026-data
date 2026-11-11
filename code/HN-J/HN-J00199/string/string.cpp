#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
char s[200005];
long long a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		cin >> s[i];
	}
	
	int i = 1, j = n;
	while(i < j) {
		if(s[i] != s[j]) {
			if(a[i] > a[j]) {
				ans += a[j];
				a[i] -= a[j];
				j -= 1;
			}
			else if(a[i] == a[j]) {
				ans += a[j];
				a[i] -= a[j];
				j -= 1;
				i += 1;
			}
			else {
				ans += a[i];
				a[j] -= a[i];
				i += 1;
			}
		}
		else {
			if(a[i] > a[j]) {
				a[i] -= a[j];
				j -= 1;
			}
			else if(a[i] == a[j]) {
				a[i] -= a[j];
				j -= 1;
				i += 1;
			}
			else {
				a[j] -= a[i];
				i += 1;
			}
		}
		
	}
	
	cout << ans;
	
	return 0;
} 
