#include <bits/stdc++.h>
using namespace std;

const int maxn = 520;
const int maxm = 5e5 + 10;

int c, n, m, d, q;

vector<int> xian[maxn];
vector<pair<int, int> > zhan[maxm];  //到哪条线、时间 
int chu[maxm], from[maxm], to[maxm];
int pai[1010][520], si[1010]; // pai[i][j]:第i站，j号线存在zhan里的第几个；si[i]第i站有几个了 
bool vis[1010];
long long mi;
int dao[maxm];
vector<int> g[maxm];


void dfs(int now, int to, long long use){
	if(now == to){
		mi = min(use, mi);
		return;
	}
	for(int i = 0; i < zhan[now].size(); i++){
		int x = zhan[now][i].first, t = zhan[now][i].second, t2 = 0;
		for(int j = 0; j < xian[x].size(); j++){
			int nxt = xian[x][j];
			if(vis[nxt]) continue;
			for(int k = 0; k < zhan[nxt].size(); k++){
				int wu = zhan[nxt][k].first;
				if(wu == x){
					t2 = zhan[nxt][k].second;
					break;
				}
			}
			vis[nxt] = true;
			dfs(nxt, to, use + t + t2);
			vis[nxt] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> chu[i];
	if(c <= 11){
		for(int i = 1; i <= n; i++){
			int ge;
			cin >> ge;
			for(int j = 1; j <= ge; j++){
				int aa, tt;
				cin >> aa >> tt;
				xian[i].push_back(aa);
				zhan[aa].push_back({i, tt});
				si[aa]++;
				pai[aa][i] = si[aa];
			}
		}
		for(int i = 1; i <= q; i++){
			cin >> from[i] >> to[i];
		}
		for(int i = 1; i <= q; i++){
			mi = 0x3f3f3f3f3f3f3f3f;
			int ff = from[i], tt = to[i];
			memset(vis, 0, sizeof(vis));
			dfs(ff, tt, 0);
			cout << mi + chu[ff] + chu[tt] << '\n';
		}
	}
//	else{
//		for(int i = 1; i <= n; i++){
//			int ge;
//			cin >> ge;
//			for(int j = 1; j <= ge; j++){
//				cin >> dao[j];
//			}
//			for(int j = 1; j <= ge; j++){
//				for(int k = 1; k <= ge; k++){
//					if(k == j) continue;
//					g[j].push_back(k);
//				}
//			}
//		}
//		for(int i = 1; i <= q; i++){
//			cin >> from[i] >> to[i];
//		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 0; j < g[i].size(); j++){
//				cout << g[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

//输入的第一行包含五个非负整数 c, n, m, d, q，分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
0 3 4 4 1
4 4 4 4
2 1 1 2 1
2 2 1 3 1
2 3 1 4 1
2 3

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

