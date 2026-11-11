#include<bits/stdc++.h>
using namespace std;
long long a[200009], ans[4000000009], q = 1, Max = -1e9;
long long n, m;
bool  b = 0;
int A(int x, int y) {
	return x < y;
}
int main () {
	freopen ("and.in" , "r", stdin);
	freopen ("ans.out" , "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	Max = max(Max, a[i]);
    	if (a[i] == i - 1) b = 1;
//    	if (a[i] >= 4)
	}
	if (m == 1) {
		cout << Max;
		return 0;
	} else if (m == 2) {
		long long x;
		for (int i = 1; i <= x; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans[q] = a[i] & a[j];
				Max = max (Max, ans[q]);
			}
			cout << Max;
			return 0;
		}
	} else if (m == n) {
		long long x;
		for (int i = 1; i <= n; i++) {
			x = (x & a[i]);
		}
		cout << x;
		return 0;
    	} //else if (m == n - 1) {
//		for (int i = 1; i <= n; i ++) {
//			
//		}
//	} else if (b == '1') {
//		sort (a + 1; a + 1 + n, A);
//		long long x;
//		if (a[1] % 2 == 0) {
//			for (int i = 1; i <= n)
//		}
//	} else if (a == 0) {
//		
//	}
	return 0;
} 
