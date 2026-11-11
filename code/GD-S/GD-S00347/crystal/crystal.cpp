#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5e5 + 10;
int n, m, a[MAX];
int Ans, Sum[MAX];

int find(int l, int r, int tar) {
	int res = r, tr = r;
	
	while(l <= r) {
		int mid = (l + r) >> 1;
		
		int A = tar * (tr - mid);
		int B = Sum[tr - 1] - Sum[mid - 1];
		
		if(A - B <= m) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	
	return res;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i++) {
		Sum[i] = Sum[i - 1] + a[i];
	}
	
	for(int i = 1; i <= n; i++) {
		int res = find(1, i, a[i]);
		Ans = max(Ans, i - res + 1);
	}
	
	cout << Ans << endl;
	
	return 0;
}
/*
5 5
1 2 4 8 9
0 1 

5 8
-3 -1 2 2 7

10 10
-3 35 3 2 1 7 34 35 -2 3
*/
