#include <bits/stdc++.h>
int c, n, m, d, q;//分别表示c测试点编号、n地铁线路数、m地铁站数、d每个地铁站最多被几条线路经过，q以及出行计划数
int f[505][1000005], r[505][1000005];//其中f表示第i条线路经过的第j个地铁站,  r表示从该地铁站的站厅走到第i条线路的站台需要的时间
int w[1000005];//表示从每个地铁站的地铁口走到站厅需要的时间
int l, a[1000005], b[1000005];//表示第r个出行计划的起点和终点所在的地铁站编号
int map1[1001][1001], z[1001][1001][3];
const int o = 10000005;
using namespace std;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cout << c << n << m << d << q;
	for (int i = 1;i <= 1000;i++){
		for (int j = 1;j <= 1000;j++){
			map1[i][j] = o;
		}
	}
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= q;i++){
		int k;
		cin >> k;
		for (int j =1;j <= k;j++){
			cin >> f[i][j] >> r[i][j];
		}
		for (int ii = 1;ii <= k;ii++){
			for (int jj = 1;jj <= ii;jj++){
				map1[ii][jj] = r[i][ii]+r[i][jj];
				map1[jj][ii] = r[i][ii]+r[i][jj];
				z[ii][jj][1]=z[jj][ii][1]=i;
				z[ii][jj][2]=z[jj][ii][2]=i;
			}
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = i;j <= m;j++){
			if(map1[i][j] != o){
				for (int k = 1;k <= m;k++){
					if (map1[k][j] != o){
						if(j >= k){
							map1[i][k] = map1[k][i] = min(map1[i][k], map1[i][j] + map1[j][k]+r[z[i][k][2]][i]+r[z[i][j][1]][i]);
							z[k][j][1]=z[j][k][1]=z[i][k][2];
							z[k][j][2]=z[j][k][2]=z[i][j][2];
						}
					}
				}
			}
		}
	}
	cin >> q;
	for (int i = 1;i <= q;i++){
		cin >> a[i] >> b[i];
		cout << w[a[i]]+w[b[i]]+map1[a[i]][b[i]] << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
