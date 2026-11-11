#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > vec[500200];
int w[500200];
int k[500200];
int a[501][50001];
int t[501][50001];
bool f[501][50001];
bool cc[500500];
vector<pair<int,int> > vec1[500500];
int dfs(int u, int v,int now, int oo, int fa){
	if(now % 1000 == v){
		for(int i = 1;i <= k[now / 1000];i++){
			if(a[now/1000][i] == v) {
				oo += t[now/1000][i];
				break;
			}
		}
		return oo;
	}
	int maxn = 0x3f3f3f3f;
	for(pair<int,int> i : vec[now]){
		if(i.first == fa) continue;
		if(cc[i.first]) continue;
		cc[i.first] = 1;
		maxn = min(maxn, dfs(u, v, i.first, oo + i.second, now));
		cc[i.first] = 0;
	}
	return maxn;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			vec1[a[i][j]].push_back({i, t[i][j]});
			if(j != 1) vec[a[i][j] + i * 1000].push_back({a[i][j - 1] + i * 1000, 0});
			if(j != 1) vec[a[i][j - 1] + i * 1000].push_back({a[i][j] + i * 1000, 0});
		}
	}
	for(int i = 1;i <= m;i++){
		for(int bb = 0;bb < vec1[i].size();bb++){
			for(int cc = bb + 1; cc < vec1[i].size(); cc++){
				pair<int,int> j = vec1[i][bb];
				pair<int,int> k = vec1[i][cc];
				vec[i + j.first * 1000].push_back({i + k.first * 1000, j.second + k.second});
				vec[i + k.first * 1000].push_back({i + j.first * 1000, j.second + k.second});
			}
		}
		for(int bb = 0;bb < vec1[i].size();bb++){
				pair<int,int> k = vec1[i][bb];
				vec[i].push_back({i + k.first * 1000, k.second});
		}
	}
	while(q--){
		int x, y; cin >> x >> y;
		cout << dfs(x, y, x, 0, 0) + w[x] + w[y] << endl;
	}
} 
