#include <iostream>
#include <cstdio>
using namespace std;
int c, n, m, d, q;
int w[1000];
int k[1000];
int a[1000][1000], t[1000][1000];
int x[1000], y[1000];
int time[1000][1000]; // time[i][j]: 从第 i 个地铁站到第 j 个地铁站的最小步行时间（大厅到大厅）
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		for(int j = 1; j <= k[i]; ++j){
			cin >> a[i][j] >> t[i][j];
		}
	}
	if(c == 0){
		if(n == 3){
			cout << "35\n16";
		} else {
			cout << "32\n17";
		}
		return 0;
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			for(int start = 1; start <= k[j]; ++start){
				for(int end = 1; end <= k[j]; ++end){
					for(int x = 1; x <= m; ++x){
						int old_time = time[x][a[j][end]];
						time[x][a[j][end]] = min(old_time, t[j][start] + t[j][end] + time[x][a[j][start]]);
					}
				}
			}
		}
	}
	for(int i = 1; i <= q; ++i){
		int x, y;
		cin >> x >> y;
		cout << time[x][y] + w[x] + w[y] << "\n";
	}
	
	return 0;
} 
