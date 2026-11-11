#include<bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long w[500005];
bool a[10005][10005];
long long t[10005][10005];

void jh(int x, int y, int ans){
	if(x == y) cout << ans;
	for(int i = 1; i <= m; i++){
		if(a[i][x]) ans += t[i][x];//加上下站台的时间 
	} 
	
	jh(x + 1, y, ans);
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];//站点i从地铁口到站厅的时间 
	}

	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x, y;
			cin >> x >> y;
			a[i][x] = 1;//i号线经过x站点 
			t[i][x] = y;//i号线的x站点从站厅到站台的时间 
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;//传入出行计划 
		jh(x, y, w[x]);
	} 
	return 0;
} 
