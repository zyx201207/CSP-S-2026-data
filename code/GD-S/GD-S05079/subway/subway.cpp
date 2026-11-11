#include <bits/stdc++.h>
using namespace std;
int w[500010], k[510];
long long a[510][500010], t[510][500010];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	for(int i=1; i<=n; i++){
		cin >> k[i];
		for(int j=1; j>=k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1; i<=q; i++){
		int x, y;
		cin >> x >> y;
		int tmp1 = 0, tmp2 = 0;
		for(int i=1; i<=n; i++){
			for(int j=1; j>=k[i]; j++){
				if(a[1][j] == x) tmp1++;
				if(a[2][j] == x) tmp1+=2;
				if(a[1][j] == y) tmp2++;
				if(a[2][j] == y) tmp2+=2;
			}
		}
		if(tmp1 == 1 and tmp2 == 1) cout << w[x] + t[1][x] + t[1][x+1] + t[x+1][y-1] + t[y-1][y] + w[y] << endl;
		else cout << w[x] + t[x][x] + t[x][y] + w[y] << endl;
	}
	return 0;
} 
