#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int a[N], p[32], sum[32];
bool b[N][32];
bool f[N];
signed main(){
//	freopen("and.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (m == 2 && n <= 2000){
		int ret = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				ret = max(ret, a[i] & a[j]);
			}
		}
		cout << ret;
		return 0;
	}
	p[0] = 1;
	int minn = 0;
	int maxp = 0;
	for (int i = 1; i < 32; i++){
		p[i] = p[i - 1] * 2;
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		minn = max(minn, a[i]);
		int j = 0;
		while(a[i] > p[j]){
			j++;
		}
		j--;
		int v = a[i];
		while(v >= p[j]){
			v -= p[j];
			b[i][j] = 1;
			sum[j]++;
			if (sum[j] >= m){
				maxp = max(maxp, j);
			}
			if (j != 0) j--;
			else break;
		}
	}
//	cout <<maxp << '\n';
	if (minn == 0){
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= n; i++){
		if (b[i][maxp] == 1){
			f[i] = 1;
//			cout << a[i] << ' ';
		}
	}
//	cout << '\n';
	int ret = p[maxp];
	for (int i = maxp - 1;  i >= 0; i--){
		int sum = 0;
		for (int j = 1; j <= n; j++){
//			if (i == 0) cout << f[j];
			if (f[j] == 1 && b[j][i] == 1){
//				if (i == 0) cout << a[j] << ' ';
				sum++;
			}
		}
		if (sum >= m){
//			cout <<i << '\n';
			ret += p[i];
			for (int j = 1; j <= n; j++){
				if (f[j] == 1 && b[j][i] == 0) f[j] = 0;
			}
		}
	}
	cout << ret;
}
