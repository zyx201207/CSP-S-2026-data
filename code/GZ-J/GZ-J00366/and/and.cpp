//GZ-J00366 贵阳市第一实验中学 孟杰锐
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, cnt, sumn;
int a[N], b[N];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a+1, a+1+n, cmp);
	
	for (int i = 1; i <= n; i++) cnt = a[1];

	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			cout << a[1];
			return 0;
		}
	} else if (m == n) {
		for (int i = 2; i <= n; i++) {
			cnt = (cnt & a[i]);
		}
		
		cout << cnt;
	}
	else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				sumn++;
				b[sumn] = (a[i] & a[j]);
			}
		}
		sort(b+1, b+1+sumn, cmp);
		for (int i = 1; i <= sumn; i++) {
			cout << b[1];
			return 0;
		}
	}
	
	
		return 0;
}
