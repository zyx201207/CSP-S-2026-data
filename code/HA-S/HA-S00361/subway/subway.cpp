#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int read(){
	int t = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return f * t;
}
int n, m, d, q;
const int N = 500 + 10, M = 5e5 + 10;
vector<int>e[N], v[N];
vector<int> tp[M], tpp[M];
int dis[N][N];
int mp[M];
int a[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	read();
	n = read();
	m = read();
	d = read();
	q = read();
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; i++){
		a[i] = read();
	} 
	for(int i = 1; i <= n; i++){
		int k = read();
		dis[i][i] = 0;
		for(int j = 1; j <= k; j++){
			int id = read(), val = read();
			e[i].push_back(id);
			v[i].push_back(val);
			tp[id].push_back(i);
			tpp[id].push_back(val);
		}
	}
	memset(mp, 0x3f, sizeof mp);
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < tp[i].size(); j++){
			for(int k = j + 1; k < tp[i].size(); k++){
				dis[tp[i][j]][tp[i][k]] = min(dis[tp[i][j]][tp[i][k]], tpp[i][j] + tpp[i][k]);
				dis[tp[i][k]][tp[i][j]] = min(dis[tp[i][k]][tp[i][j]], tpp[i][j] + tpp[i][k]);
			}		
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int i = read(), j = read();
		int ans = 1e18; 
		for(int t1 = 0; t1 < tp[i].size(); t1 ++){
			for(int t2 = 0; t2 < tp[j].size(); t2 ++){	
				ans = min(ans, dis[tp[i][t1]][tp[j][t2]] + tpp[i][t1] + tpp[j][t2]);
			}
		}
		cout << ans + a[i] + a[j] << '\n';
	}
	return 0;
}
