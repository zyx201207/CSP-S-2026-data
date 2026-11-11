#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 10;
const int M = 5e5 + 10;
const int R = 1e5 + 10;
const int K = 1e5 + 10;
int c, n, m, d, q;
int w[M];
int k[K];
int a[N][K], t[N][K];
int x[R], y[R];
void solve(int k){
	for (int l = 1;l < k;l++){
		int s = x[l], e = y[l];
		int ans = 0;
		ans += w[s];
		for (int j = 1;j <= n;j++)
			for (int i = 1;i <= e;i++){
				ans += t[j][i];
			}
		ans += w[e];
		cout << ans << '\n';
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int j = 1;j <= n;j++){
		cin >> k[j];
		for (int i = 1;i <= k[j];i++){
			cin >> a[j][i] >> t[j][i];
		}
	}
	int j = 1;
	while(cin >> x[j] >> y[j]) j++;
	
	solve(j);
	return 0;
}
