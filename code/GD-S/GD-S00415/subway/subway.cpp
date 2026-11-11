#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 5e5 + 5;
int c, n, m, d, q;
int k[505], x[M], y[M];
ll w[M], a[55][M], t[55][M];
ll ans[2];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1;i <= q;i++) cin >> x[i] >> y[i];
	for(int i = 1;i <= q;i++){
		for(int j = x[i];j <= y[i];j++){
			ans[i] += a[i][j] + t[i][j];
		}
	}
	for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
