//subway, only for special B, that testpoint 12 - 19.
#include<bits/stdc++.h>
using namespace std;
long long int c, n, m, d, q, w[500005], k, floyd[16305][16305], a[500005], t[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;i<=m;j++){
			floyd[i][j] = floyd[j][i] = 2000000005;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[j] >> t[j];
		}
		for(int x=1;x<=k;x++){
			for(int y=1;y<=k;y++){
				floyd[a[x]][a[y]] = floyd[a[y]][a[x]] = 1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				floyd[i][j] = floyd[j][i] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin >> x >> y;
		cout << (t[1]*2*floyd[x][y] + w[x] + w[y]) << "\n";
	}
}
