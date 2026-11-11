#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5;
const int Q = 1e5 + 5;
int c, n, m, d, q;
int w[M], k[505], a[505][M], t[505][M], x[Q], y[Q];
int main() { 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j]; 
		}
	}
	for(int i = 1; i <= q; i++) cin >> x[i] >> y[i];
	
	return 0;
} 
