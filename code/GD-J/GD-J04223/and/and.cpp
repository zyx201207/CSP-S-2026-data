#include <bits/stdc++.h>
using namespace std;
int a[10384543];
int b[12345433];
int main() {
	freopen("and.in", "s", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	const int M = m+2;
	sort (a + 1, a + n + 1);
	int m1[M];
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i - 1])maxn = a[i];
	}
	int maxnn = -1;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i - 1]){
			cnt ++;
			maxn &= a[i];
			a[i] = 0;
		}
		if(cnt == m)break;
	}
	if(cnt == m)cout << maxn;
	else {
		sort(a + 1, a + n + 1);
		for(int i = n; i >= 1; i--) {
			if(maxn == 0)maxn = a[i];
			else
				maxn &= a[i];
			cnt++;
			if(cnt == m)break;
		}
		cout << maxn;
	}
	return 0;
}//为何不让运行
