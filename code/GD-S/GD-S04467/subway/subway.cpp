#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int c, n, m, d, q;
int W[N], k[N];
int x, y;

struct node{
	int v, w; 
};
vector<node> g[N];
int ans;
bool vis[N];
int s[500][500], t[500][500];
void dfs(int u, int ride, int R, int T){
	if(u == y){
		ans = min(ans, T);
		return ;
	}
	for(auto edge : g[u]){
		int v = edge.v;
		int w = edge.w;
		if(v > 1000){
			if(ride == 0 && u < 1000 && !vis[v]){
				vis[v] = true;
				dfs(v, 1, v, T + w);
				vis[v] = false;
			}else if(ride == 1 && u < 1000 && !vis[v]){
				vis[v] = true;
				dfs(v, 2, v, T + w);
				vis[v] = false;
			}
		}else if(v < 1000){
			if(ride == 2 && u > 1000 && !vis[v]){
				vis[v] = true;
				dfs(v, 1, R, T + w);
				vis[v] = false;
			}else if(ride == 1 && u > 1000 && !vis[v]){
				vis[v] = true;
				dfs(v, 1, R, T);
				vis[v] = false;
			}
		}
	}
	return ;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> W[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> s[i][j] >> t[i][j];
			g[i+1000].push_back({s[i][j], t[i][j]});
			g[s[i][j]].push_back({i+1000, t[i][j]});
		}
	}
	while(q--){
		cin >> x >> y;
		ans = 1e8;
		dfs(x, 0, -1, W[x] + W[y]);
		cout << ans << endl;
		/*vector<int> rA(N);
		vector<int> rB(N);
		int len1 = 0, len2 = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++){
				if(x == s[i][j]){
					len1++;
					rA[len1] = i;
				}
			}
		
		for(int i = 1; i <= len1; i++){
			dfs(x, );
		}*/
		/*bool is1 = false;
		sort(rA.begin(), rA.end());
		sort(rB.begin(), rB.end());
		for(int i = 1; i <= len1; i++){
			for(int j = 1; j <= len2; j++){
				if(rA[i] == rB[j]){
					is1 = true;
					for(int l = 1; l <= k[rA[i]]; l++){
						if(s[rA[i]][l] == x){
							T += t[rA[i]][l];
						}else if(s[rA[i]][l] == y){
							T += t[rA[i]][l];
						}
					}
				}
			}
		}
		if(is1){
			cout << T << endl;
			continue;
		}*/
	}
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
