#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 100005

ll c, n, m, d, q;
ll w[maxn];
ll k[maxn];
ll a[maxn][3];
ll t[maxn][3]; // i站->厅用时 


ll calc_go_atob(ll a_, ll b_) {
	for (ll i=1;i<=n;i++) {
		bool yesa = 0, yesb = 0;
		for (ll j=1;j<=k[i];j++) {
			if (a[i][j] == a[i][a_]) {
				yesa = 1;
			} else if (a[i][j] == a[i][b_]) {
				tesb = 1;
			}
			if (yesa and yesb) 
		}
	}
} 

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	
	cin >> c >> n >> m >> d >> q;
	for (ll i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++) { // 地铁站数 
		cin >> k[i];
		for (int j=1;j<=k[i];j++) {
			cin >> a[i][j] >> t[i][j]; map
/*
a[i,j] 表示第 i 条线路经过的第 j 个地铁站
t[i,j] 表示从该地铁站的站厅走到第 i 条线路
的站台需要的时间
*/
		}
	}
	for (ll i=1;i<=q;i++) {
		cin >> x[i] >> y[i] // 表示出行计划的起点和终点所在的地铁站编号
		
	}
	// 哭哭 
}
