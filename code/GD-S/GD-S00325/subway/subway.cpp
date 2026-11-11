#include <iostream>
#include <vector>
using namespace std;
const int N = 5*1e5 + 7;
int c, n, m, d, p;
int a[N];
struct o{
	int y, w;//第y个点的代价 
};
vector <o> b[1020];
int mn[1050][1020];
bool vis[N],vis2[N];
vector <o> g[N];
int st, ed, ans = 0x3f3f3f3f;
void f(int x, int w){
//	cout <<x << " " << w << endl;
	if(x == ed){
		ans = min(ans, w);
		return ;
	}
	for(int i = 0; i < g[x].size(); i++){
		int y1 = g[x][i].y;//线路 
		if(!vis[y1]){//线路没走过 
			vis[y1] = true;
			for(int j = 0; j < b[y1].size(); j++){
				int p = b[y1][j].y;//选取的点 
				int w2 = b[y1][j].w;//选取点在该线代价 
				int w1 = g[x][i].w;//当前点在该线代价 
				if(!vis2[p] && p != x){//点没走过 
					vis2[p] = true;
//					cout << "起点:" << x << "终点：" << p << "线路" << y1 << "  " << w1 << " " << w2 << endl;
					f(p, w + w1 + w2);
					vis2[p] =false;
				}
			}
			vis[y1] = false;
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	if(c >= 7 && c <= 11){//双向边图 (单源带权最短路，弗洛伊德算法, 15分)
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				mn[i][j] = 0x3f3f3f3f;
			}
		}
		for(int i = 1; i <= m; i++){
			mn[i][i] = 0;
		}
		for(int i = 1; i <= n; i++){
			int x0,x1, x2, x3, x4;
			cin >> x0 >> x1 >> x2 >> x3 >> x4;
			g[x1].push_back({x3, x2});//到x3代价x2 
			g[x3].push_back({x1, x4});
			mn[x3][x1] = mn[x1][x3] = min(mn[x1][x3], x2 + x4);
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				for(int k = 1; k <= m; k++){
					mn[i][j] = min(mn[i][j], mn[i][k] + mn[k][j]);
					mn[j][i] = min(mn[j][i], mn[j][k] + mn[k][i]);
				}
			}
		}
		for(int i = 1; i <= p; i++){
			cin >> st >> ed;
			cout << mn[st][ed] + a[st] + a[ed] << endl;
		}
	}else if(c >= 12 && c <= 15){
		
	}else{//暴力得分 (12分) 
		for(int i = 1; i <= n; i++){
			int k;
			cin >> k;
			for(int j = 1; j <= k; j++){
				int x1, x2;
				cin >> x1 >> x2;
				g[x1].push_back({i, x2});
				b[i].push_back({x1, x2});//第i条线有x1点 
			}
		}
		for(int i = 1; i <= p; i++){
			for(int i = 0; i <= m; i++){
				vis[i] = false;
			}
			ans = 0x3f3f3f3f;
			cin >> st >> ed;
			f(st, 0);
			cout << ans + a[st] + a[ed] << endl;
		}
	}
	return 0;
} 
/*
*/
