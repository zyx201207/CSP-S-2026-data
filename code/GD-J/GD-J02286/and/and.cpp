#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], mxa, mxb, mxc, num;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int na = n, ma = m - 1;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	while (ma--) {
		num++;
		int ia, ja;
		if(ma < m - 2) {
			for (int i = na - 1; i >= na - 1; i--) {
				if(a[i] & mxb > mxc) {
					mxc = a[i] & mxb;
					ia = i;
				}
				if((mxb >> 1) > a[i] && i < na) break;
			} 
			a[ia] = a[--na];
		}
		else {
			for (int i = na - 1; i >= 0; i--) {
				for (int j = i - 1; j >= 0; j--) {
					if(a[i] & a[j] > mxa){
						mxa = a[i] & a[j];
						ia = i, ja = j;
					}
					if((a[i - 1] >> 1) > a[j] && j < i - 1) break;
				}
			} 
			a[ia] = a[--na];
			a[ja] = a[--na];
			mxb = mxa;
		}
	}
	cout << mxc;
	return 0;
}

