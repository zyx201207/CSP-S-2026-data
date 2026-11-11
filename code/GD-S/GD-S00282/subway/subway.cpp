#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 10, N = 500 + 10;
int c, n, m, d, q, w[M], k[N], l, st, en, ans = 2e18, x, y;
vector<int> a[N], t[N];
struct node{
	int x, y;
};
vector<node> g[N];
void dfs(int x, int y, int dis){
//	cout << x << " " << y << " " << dis << "\n";
	if(x != 0 && a[x][y] == en){
		ans = min(ans, dis + t[x][y]);
		return ;
	}
	if(y == 0) dis += w[st];
	if(x == 0 && y == 0){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= k[i];j ++){
				if(a[i][j] == st){
//					cout << i - 1 << " " << j - 1 << "\n";
					dfs(i, j, dis + t[i][j]);
				}
			}
		}
	}else{
		for(auto i : g[(x == 0 ? st : a[x][y])]){
			if(i.x != x){
				dfs(i.x, i.y, dis + t[i.x][i.y] + t[x][y]);
			}else{
				dfs(i.x, i.y, dis);
			}
			
		}
	}
	
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j = 1;j <= k[i];j ++){
			cin >> x >> y;
			a[i].push_back(x);
//			cout << a[i][j];
			t[i].push_back(y);
			if(j > 1) g[a[i][j - 1]].push_back({i, j});
		}
	}
	while(q --){
		cin >> st >> en;
		ans = 2e18;
		dfs(0, 0, 0);
		cout << ans + w[en] << "\n";
	}
	return 0;
}
