#include <bits/stdc++.h>
using namespace std;
struct node{
	int k;//第 i 条线路经过的地铁站数
	int a[500005]; //ai,j表示第i条线路经过的第j个地铁站
	int t[500005];//ti,j表示从该地铁站的站厅走到第i条线路的站台需要的时间
};
node sub[505];
//c测试点编号  n地铁线路数  m地铁站数  d每个地铁站最多被几条线路经过  q出行计划数
int c, n, m, d, q, w[500005]; //w每个地铁站的地铁口走到站厅需要的时间
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++){
		cin >> sub[i].k;
		for(int j=1; j<=sub[i].k; j++){
			cin >> sub[i].a [j] >> sub[i].t [j];
		}
	}
	for(int i=1; i<=q; i++){
		int s, e;
		cin >> s >> e;
		
	}
	return 0;
}
