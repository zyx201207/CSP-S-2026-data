#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e3+5
;
int c, t, n, d, x[N], ans, cnt[N][N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		memset(x, 0, sizeof(x));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}
//		for (int i = 1; i <= n; i++){
//			cnt[i][i] = 1;
//		}
		for (int u = 1; u < n; u++){
			for (int v = u+1; v <= n; v++){
				int i = u, j = u;
				while (i < v){
					while(x[i+1]-x[j] <= d && i < v){
			 			i++;
					}
					cnt[u][v]++;
					j = i;
				}
			}
		}
//		for (int u = 1; u < n; u++){
//			for (int v = u+1; v <= n; v++){
//				if (cnt[u][v] == 2){
//					ans++;
//				} 
//			}
//		}
		cout << ans << endl;
	}
	return 0;
}
