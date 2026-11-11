#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010;
int n, m;
int a[N], pre[N], f[N][N];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = max(pre[i-1], a[i]);
	}
	for(int i = 1; i <= n; i++){
		f[i][1] = pre[i];
		for(int j = 1; j <= m; j++){
			f[i][j] = max({f[i][j], f[i-1][j], (f[i-1][j-1] & a[i])});
		}
	}
	cout << f[n][m];
	return 0;
}
