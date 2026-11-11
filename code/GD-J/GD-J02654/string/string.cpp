#include<bits/stdc++.h>
using namespace std;
struct b{
	long long a;
	char c;
} d[200009];
long long ans = 0;
int main (  ) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> d[i].a >> d[i].c;
	if(n % 2 == 1) {
		for(int i = 1; i <= n / 2; i++) {
			if(d[i].a == d[n + 1 - i].a) {
				if(d[i].c != d[n + 1 - i].c) ans += d[i].a;
			}
			else if(d[i].a < d[n + 1 - i].a) {
				if(d[i].c != d[n + 1 - i].c) {
					if(d[i + 1].c != d[n + 1 - i].c) ans += d[n + 1 - i].a;
					else ans += d[i].a;
				}
				else {
					if(d[i + 1].c != d[n + 1 - i].c) ans += (d[n + 1 - i].a - d[i].a);
					d[i + 1].a -= (d[n + 1 - i].a - d[i].a);
				}
			}
			else {
				if(d[i].c != d[n + 1 - i].c) {
					if(d[i + 1].c != d[n + 1 - i].c) ans += d[i].a;
					else ans += d[n + 1 - i].a;
				}
				else {
					if(d[i + 1].c != d[n + 1 - i].c) ans += (d[i].a - d[n + 1 - i].a);
					d[i + 1].a -= (d[i].a - d[n + 1 - i].a);
				}
			}
		}
	}
	else {
		for(int i = 1; i <= n / 2; i++) {
			if(d[i].a == d[n + 1 - i].a) {
				if(d[i].c != d[n + 1 - i].c) ans += d[i].a;
			}
			else if(d[i].a < d[n + 1 - i].a) {
				if(i == n / 2) {
					if(d[i].c != d[n + 1 - i].c) ans += d[i].a;
				}
				else if(d[i].c != d[n + 1 - i].c) {
					if(d[i + 1].c != d[n + 1 - i].c) ans += d[n + 1 - i].a;
					else ans += d[i].a;
				}
				else {
					if(d[i + 1].c != d[n + 1 - i].c) ans += (d[n + 1 - i].a - d[i].a);
					d[i + 1].a -= (d[n + 1 - i].a - d[i].a);
				}
			}
			else {
				if(i == n / 2) {
					if(d[i].c != d[n + 1 - i].c) ans += d[n + 1 - i].a;
				}
				else if(d[i].c != d[n + 1 - i].c) {
					if(d[i + 1].c != d[n + 1 - i].c) ans += d[i].a;
					else ans += d[n + 1 - i].a;
				}
				else {
					if(d[i + 1].c != d[n + 1 - i].c) ans += (d[i].a - d[n + 1 - i].a);
					d[i + 1].a -= (d[i].a - d[n + 1 - i].a);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
