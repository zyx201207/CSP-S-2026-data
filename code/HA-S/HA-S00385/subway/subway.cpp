#include <bits/stdc++.h>
using namespace std;
int w[55], a[3][55], t[3][(int)1e6+5];
int min(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(t, 0x3f, sizeof(t));
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for (int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for (int j=1;j<=k;j++) {
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	}
	int les = 0x3f3f3f3f;
	for (int i=1;i<=m;i++) {
		if (t[1][i] != 0x3f3f3f3f && t[2][i] != 0x3f3f3f3f) {
			les = min(les, t[1][i] + t[2][i]);
		}
	}
	for (int i=1;i<=q;i++) {
		int x, y;
		cin>>x>>y;
		if (t[1][x] != 0x3f3f3f3f && t[2][x] != 0x3f3f3f3f &&
		  t[1][y] != 0x3f3f3f3f && t[2][y] != 0x3f3f3f3f) {
			cout<<min(w[x] + t[1][x] + les + t[2][y] + w[y], 
					w[x] + t[2][x] + les + t[1][y] + w[y],
					w[x] + t[1][x] + t[1][y] + w[y],
					w[x] + t[2][x] + t[2][y] + w[y]);
		}
		if ((t[1][x] != 0x3f3f3f3f && t[2][x] == 0x3f3f3f3f &&
		  t[1][y] != 0x3f3f3f3f && t[2][y] != 0x3f3f3f3f) ||
		  (t[1][x] == 0x3f3f3f3f && t[2][x] != 0x3f3f3f3f &&
		  t[1][y] != 0x3f3f3f3f && t[2][y] != 0x3f3f3f3f)) swap(x, y);
		if (t[1][x] != 0x3f3f3f3f && t[2][x] != 0x3f3f3f3f &&
		  t[1][y] != 0x3f3f3f3f && t[2][y] == 0x3f3f3f3f) {
			cout<<min(w[x] + t[1][x] + les + t[2][y] + w[y], 
					w[x] + t[2][x] + t[2][y] + w[y]);
		}
		if (t[1][x] != 0x3f3f3f3f && t[2][x] != 0x3f3f3f3f &&
		  t[1][y] == 0x3f3f3f3f && t[2][y] != 0x3f3f3f3f) {
			cout<<min(w[x] + t[1][x] + les + t[2][y] + w[y], 
					w[x] + t[2][x] + t[2][y] + w[y]);
		cout<<'\n';
		}
	}
	return 0;
}
