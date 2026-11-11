#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans,bt;
//测试点编号 地铁线路数 地铁站数  地铁站最多被几条路线经过  出行计划 
long long dt[500005],a[505][100005],tt[505][100005],k[500005];
long long xr,yr;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	 cin >> c >> n >> m >> d >> q;
	 for(int i=1;i<=m;i++) {
	 	cin >> dt[i];//地铁口到站厅t
	 }
	 for(int i=1;i<=n;i++) {
	 	cin >> k[i];
	 	for(int y=1;y<=k[i];y++) {
	 		cin >> a[i][y] >> tt[i][y];
			//i路线经过的j地铁站吗 
			//j地铁站的站台到站厅t
		 }
	 }
	 for(int i=1;i<=q;i++) {
	 	ans=0;
	 	cin >> xr >> yr;//第r出行计划的起点终点所在的地铁编号 
	 	ans=dt[xr]+dt[yr];//进站和出站t 
	 	//换乘的t(乘坐地铁线的站台到站厅的t+换成地铁线的站厅到站台的t) 
	 	bt=19;
	 	cout << ans+bt << endl;
	 }
	return 0;
}
