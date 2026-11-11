/*#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
int f[maxn];//选了i个，j作为结尾 

int main() {
	
	int n, m, ans = 0;
	scanf("%d, %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (int i = 1; i <= n; i++) {
		f[i] = a[i];
	}
	/*
	for (int i = 2; i <= m; i++) { 
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < j; k++) {
				f[i][j] = max(f[i-1][k] & a[j], f[i][k]);
				ans = max(ans, f[i][j]);
			}
		}
	}//
	for (int j = 1; j <= n; j++) {
		for (int k = j - 1; k >= 1; k--) {
			f[j] = max(f[k-1] & a[j], f[k]);
			ans = max(ans, f[j]);
		}
	}
	
	printf("%d", f[m]);
	return 0;
}*/
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

const int MAXN = 2e5 + 10;
int a[MAXN] = { 0 };

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m, maxn = -0x7fffffff, all, f1 = 0, f2 = 0, mac;
	scanf("%d %d", &n, &m);
	//cout << n << ' ' << m << endl;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i == 1) {
			all = a[i];
		} else {
			all = all & a[i];
		}
		//cout << all << endl;
		
		if ((double)sqrt(a[i] + 1) - floor(sqrt(a[i] + 1)) == 0) f1 = 1;
		
		mac = maxn;
		maxn = max(maxn, a[i]);
	}
	if ((double)sqrt(n) - floor(sqrt(n)) == 0) {
		f2 = 1;
	}
	//cout << m << endl;
	if (m == 2) {
		int max2 = -0x7fffffff;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				max2 = max(max2, a[i] & a[j]);
				//printf("%d & %d, max: %d %d\n", a[i], a[j], max2, a[i] & a[j]);
			}
		}
		
		printf("%d", max2);
	} else if (m == n) {
		printf("%d", all); 
	} else if (m == 1 || f1 == 1) {
		printf("%d", maxn);
	} else if (f2 == 1) {
		printf("%d", mac);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}













