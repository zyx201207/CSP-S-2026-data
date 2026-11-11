#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int f[N][20];
int a[N];
void fj(int x,int h) {
	int p = 1;
	while (x) {
		int c = x % 2;
		x /= 2;
		f[h][p] = c; 
		p++;
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int res = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		fj(a[i],i);
	}
	//for (int i = 1;i <= n;i++) {
	//	for (int j = 1;j <= n;j++) {
	//		cout << f[i][j] << " ";
	//	}
	//	cout << endl;
	}
	//for (int i = 20;i >= 0;i--) {
		int s = 0;
		for (int j = 1;j <= m;j++) {
			s += f[j][i];
		}
		if (s == m) {
			res += s * pow(2,i);
		}
	}
	cout << res;
} 
