#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int ccf, n, m, d, q;
int a[N], b[N], c[N];

int tu[N][N];

int main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	cin >> ccf >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	
	int nn;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			tu[i][j] = 1145149191;
		}
	}
	for (int i = 1; i <= n; i++) tu[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> nn;
		for (int j = 1; j <= nn; j++) {
			cin >> b[j];
			cin >> c[j];
		}
		
		for (int j = 1; j <= nn; j++)
			for (int l = 1; l <= nn; l++)
				tu[b[j]][b[l]] = min(tu[b[j]][b[l]], c[l] + c[j]); 
	}
	
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= m; j++) cout << tu[i][j] << ' ';
//		cout << endl;
//	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int l = 1; l <= m; l++) {
				tu[i][l] = min(tu[i][l], tu[i][j] + tu[j][l]);
			}
		}
	}
	
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= m; j++) cout << tu[i][j] << ' ';
//		cout << endl;
//	}
	
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		
		cout << tu[u][v] + a[u] + a[v] << endl;
	}
	return 0;
}
