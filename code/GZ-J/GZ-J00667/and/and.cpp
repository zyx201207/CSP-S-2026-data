//GZ-J00667 遵义市第十二中学 陈俊熙
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (m == 1) {
        sort(a + 1, a + n + 1);
        cout << a[n];
	} else if (m == 2) {
	    int maxn = 0;
	    for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int d = a[i] & a[j];
                maxn = max(maxn, d);
            }
	    }
	    cout << maxn;
	} else if (m == 3) {
	    int maxn = 0;
	    for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    int d = a[i] & a[j] & a[k];
                    maxn = max(maxn, d);
                }
            }
	    }
	    cout << maxn;
	} else {
        cout << 0;
	}
	return 0;
}
