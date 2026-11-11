#include<bits/stdc++.h>
using namespace std;

long long n, ans;
long long a[200010];
char c[200010];
long long i, j, ai, aj;
char ci, cj;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int k = 1; k <= n; k++) {
		cin >> a[k] >> c[k];
	}
	for(i = 0, j = n + 1; ; ) {
		if(ai == 0) {
			ai = a[++i];
			ci = c[i];
		}
		if(aj == 0) {
			aj = a[--j];
			cj = c[j];
		}
		if(i >= j) break;
		if(ai == aj) {
			if(ci != cj) ans += ai;
			ai = aj = 0;
		}
		else {
			if(ai > aj) {
				if(ci != cj) ans += aj;
				ai -= aj;
				aj = 0;
			} 
			else {
				if(ci != cj) ans += ai;
				aj -= ai;
				ai = 0;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
