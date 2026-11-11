#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[50005];
int k[50005];
struct node{
	int v,w;
};
int dot(int idx, int h){//0为地铁口，1为站厅，2为站台 
	return (idx - 1) * 3 + h + 1; 
}
vector <int> a[50005];
vector <int> t[50005];

int f[3005][3005];

int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(f, 0x3f, sizeof(f));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= 3 * m; i ++){
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
		f[dot(i,0)][dot(i,1)] = w[i];
		f[dot(i,1)][dot(i,0)] = w[i];
	}
	for(int i = 1; i <= n; i ++){
		int k1;
		cin >> k1;
		k[i] = k1;
		for(int j = 1; j <= k1; j ++){
			int aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int u = 0; u < k[i]; u ++){
			for(int v = 0; v < k[i]; v++){
				f[dot(a[i][u], 1)][dot(a[i][v], 1)] = t[i][u] + t[i][v];
				f[dot(a[i][v], 1)][dot(a[i][u], 1)] = t[i][v] + t[i][u];
			}
		}
	}
	for(int zz = 1; zz <= m * 3; zz ++){
		for(int i = 1; i <= m * 3; i ++){
			for(int j = 1; j <= m * 3; j ++){
				f[i][j] = min(f[i][j], f[i][zz] + f[zz][j]);
			}
		}
	}
	for(int i = 1; i <= q; i ++){
		int beg, en;
		cin >> beg >> en;
		cout << f[dot(beg, 0)][dot(en, 0)] << endl;
	}
	return 0;
}
/*   
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

