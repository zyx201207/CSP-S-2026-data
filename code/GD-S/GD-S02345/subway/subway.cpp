#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5, M = 2e3 + 5;
ll c, n, m, d, q, w[N], a[M][M], t[M][M], x[N], y[N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	} 
	for(int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
	} 
	return 0;
}
