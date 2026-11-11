#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long x[2000010];
int a[2000010];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int c, T;
	cin >> c >> T;
	while (T--){
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)cin >> x[i];
		for (int i = 1; i <= n; i++)a[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
		int ans = 0, last = 0;
		for (int i = 1; i <= n; i++){
			if (a[i] == i){
				for (int u = last + 1; u < i - 1; u++){
					for (int v = a[u] + 1; v <= i; v++){
						int cnt = 0;
						int k, last;
						for (k = a[u], last = u; k < v; last = k, k = a[k]){
							if (k - 1 > last && a[k - 1] >= min(v, a[k]))cnt++;
							if (k - 2 > last && a[k - 2] >= min(v, a[k])){cnt = -1; break;}
						}
						ans += (cnt == 1);
					}
				}
				last = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
/*
海鸟在一条链上飞行，最远可以飞到第a[i]座岛屿 
统计所有(u,v)点对中，最短路径数恰有两个的点对数量
很明显，两个点的最短路径长度一定是每次跳到最远的位置（也有可能根本就到不了）

可恶！感觉我打的这个暴力很好维护，但是现在已经18:18了…… 
*/
