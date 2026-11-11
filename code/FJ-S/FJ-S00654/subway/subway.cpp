#include<bits/stdc++.h>
using namespace std;
int o, n, m, q, p;
long long a[500009];
struct ant{
	int x, y;
}b[509][500009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> o >> n >> m >> q >> p;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= m;i++){
		int x;
		cin >> x;
		for (int j = 1;j <= x;j++){
			cin >> b[i][j].x >> b[i][j].y;
		}
	}
	for (int i = 1;i <= p;i++){
		int x, y;
		cin >> x >> y;
		long long ct = 0;
		ct += a[x] + a[y];
		cout << ct;
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

   4  5  7  3  4
ͷ->1->2->2->3->β 9 
*/
