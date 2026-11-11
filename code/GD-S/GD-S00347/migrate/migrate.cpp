#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2e6 + 10; 
int c, t, Sum;
int n, d;
int a[MAX], b[MAX];


signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	for(cin >> c >> t; t; t--) {
		Sum = 0;
		cin >> n >> d;
		
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		
		
		for(int i = 4; i <= n; i++) {
			int l = i - 3;
//			if(a[i] - a[l] > Min) continue;
			if(a[l + 1] - a[l] <= d) {
				if(a[l + 2] - a[l + 1] <= d) {
					if(a[l + 3] - a[l + 2] <= d) {
						Sum++;
					}
				}
			}
		}
		
		cout << Sum << endl;
	}
	/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
	*/
	return 0;
}

