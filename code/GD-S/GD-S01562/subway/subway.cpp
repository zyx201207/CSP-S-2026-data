#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500010], a[510], t[510], x[100010], y[100010], sum;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
		sum += w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> t[i];
		sum += t[i];
	}
	for (int i = 1; i <= q; i++){
		cin >> x[i] >> y[i];
	}
	cout << sum;	
	return 0;
} 
