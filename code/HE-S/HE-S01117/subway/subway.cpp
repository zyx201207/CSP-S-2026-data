#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int p, t;
};
int cnt;
int dis[507][507];
int c, n, m, d, Q, w[500007];
vector<node> tmp[500007];
inline int read(){
	int k = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-'){
			f = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f * k;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	Q = read();
	for(int i = 1;i <= m;++i){
		w[i] = read();
	}
	for(int i = 1;i <= n;++i){
		int k;
		k = read();
		for(int j = 1;j <= k;++j){
			int a, t;
			a = read();
			t = read();
			cnt++;
			tmp[a].push_back({i, t});
		}
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			dis[i][j] = 4e18;
		}
	}
	for(int k = 1;k <= m;++k){
		for(int i = 0;i < tmp[k].size() - 1;++i){
			for(int j = i + 1;j < tmp[k].size();++j){
				dis[tmp[k][i].p][tmp[k][j].p] = min(dis[tmp[k][i].p][tmp[k][j].p], tmp[k][i].t + tmp[k][j].t);
				dis[tmp[k][j].p][tmp[k][i].p] = dis[tmp[k][i].p][tmp[k][j].p];
			}
		}
	}
	for(int i = 1;i <= n;++i){
		dis[i][i] = 0;
	}
	for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= Q;++i){
		int x, y;
		x = read();
		y = read();
		int ans = w[x] + w[y];
		int mn = 4e18;
		for(int i = 0;i < tmp[x].size();++i){
			for(int j = 0;j < tmp[y].size();++j){
				mn = min(mn, dis[tmp[x][i].p][tmp[y][j].p] + tmp[x][i].t + tmp[y][j].t);
			}
		}
		cout << ans + mn << '\n';
	}
	return 0;
}
