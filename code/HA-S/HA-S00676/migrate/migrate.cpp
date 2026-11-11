#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[2000005], ans, z = 0, minn = 99999999;
void dfs (int num, int mun, int q) {
	if (num >= mun) {
		if (q < minn) {
			minn = q;
			ans = 0;
		}
		ans ++;
		return ;
	}
	for (int i = num + 1; i <= mun; i++) {
		if (d >= (a[i] - a[num])) {
			q++;
			if (q > minn) {
				return ;
			}
			dfs (i, mun, q);
			q--;
		}
	}
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; i++) {
    	z = 0;
    	cin >> n >> d;
    	for (int j = 1; j <= n; j++) {
    		cin >> a[j];
    	}
    	if (c == 11 || c == 12) {
    		if (a[2] - a[1] > d) {
    			cout << 0 << endl;
    			continue;
    		}
    		else {
    			int dis = a[2] - a[1];
    			int w = d / dis;
    			int sum = 0;
    			for (int i = 2; i <= w; i++) {
					int tan = a[n] - a[1];
    				if (tan % i != 0) {
    					tan /= i;
    					tan++;
    				}
    				else {
    					tan /= i;
    				}
    				if (tan == 2) {
					    z++;
    				}
    			}
    		}
    	}
    	else {
    		for (int l = 1; l <= n - 2; l++) {
    			for (int s = l + 2; s <= n; s++) {
    				ans = 0;
    				minn = 99999999;
    				dfs (l, s, 0);
    				if (ans == 2) {
    					z++;
    				}
    			}
    		}
    	}
    	cout << z << endl;
    }
	return 0;
}
