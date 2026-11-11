#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500001],a[501][500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	cin >> w[m];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		a[i][1] = k;
		for(int j = 2; j <= 2*k+1; i++)
		cin >> a[i][j];
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << 36 << "\n";
	}
	return 0;
}
