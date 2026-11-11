#include<bits/stdc++.h>
using namespace std;

const int Q = 1e5 + 5;
int c, n, m, d, q;
int w[1005], k[1005], a[1005][1005], t[1005][1005];
int x[Q], y[Q];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}	
	for (int i = 1; i <= q; i++){
		cin >> x[i] >> y[i];
	}
	//
	for (int i = 1; i <= q; i++){
		int T = 0;
		for (int j = 1; j <= m; j++){
			T += t[i][j];
			T += w[j];
		}
		cout << T << endl;
	}
	return 0;
}