#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550, M=5e5+10, INF=1e18;
int c, n, m, d, q, w[M];
struct stop{
	int id; // 线路编号
	int t; // t(站厅到站台)
};
vector<stop>station[M];
int dis[N][N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >>c >>n >>m >>d >>q;
	for(int i=1; i<=m; i++)
		cin >>w[i];
	for(int i=1; i<=n; i++){
		int k; cin >>k;
		for(int j=1; j<=k; j++){
			int a, t;
			cin >>a >>t;
			station[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i=1; i<=n; i++)
		dis[i][i] = 0;
	for(int i=1; i<=m; i++)
		for(stop j : station[i])
			for(stop k : station[i])
				dis[j.id][k.id] = min(dis[j.id][k.id], j.t + k.t);
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
	while(q--){
		int x, y, ans = INF;
		cin >>x >>y;
		for(stop i : station[x])
			for(stop j : station[y])
				ans = min(ans, w[x] + w[y] + i.t + j.t + dis[i.id][j.id]);
		cout <<ans <<'\n';
	}
	return 0;
}

