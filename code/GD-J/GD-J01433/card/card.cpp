#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n, m, a[N], b[N], c[N];
void A(long long x, int y) {
	int ok = 0;
	for (int i = 1; i <= y; i ++) {
		if (ok) {
			a[b[i]]--;
			b[i] = 0;
		}
		if (b[i] == x) ok = 1;
	}
}
int main () {
	freopen ("card.in" , "r", stdin);
	freopen ("card.out" , "w", stdout);
    cin >> n >> m;
    int ans = 0;
    while (ans <= n) {
    	ans++;
    	for (int i = ans; i <= n; i++) {
        	long long x;
    	    cin >> x;
    	    b[i] = x;
    	    a[x]++;
        	if (a[x] > 1) {
        		A(x, i);
		    }
     	}
    	for (int i = 1; i <= n; i++) {
	    	if (b[i] != 0) c[i]++;
    	}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
} 
