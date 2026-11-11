#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q , a[5500000] , w , dis[5500][5500];
bool dfs[500010];
vector<pair<int , int>> edge[550];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
 	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
	}
	w = m;
	for (int i = 1; i <= n; i++){
		int k; cin >> k; w++;
		for (int i = 1; i <= k; i++){
			int p , dis; cin >> p >> dis;
			edge[w].push_back(make_pair(p , dis));
			edge[p].push_back(make_pair(w , dis));
		}
	}
	if (12 <= c && c <= 19){
		while (q--){
			int t , f; cin >> t >> f;
			dfs[t] = 1;
			memset(dfs , 0 , sizeof(dfs));
			queue<pair<int , int>> qu; qu.push(make_pair(f , 0));
			while (!qu.empty()){
				pair<int , int> tp = qu.front();
				qu.pop();
				if (tp.first == t){
					cout << a[f] + a[t] + tp.second << "\n";
					break;
				}
				for (auto it : edge[tp.first]){
					if (dfs[it.first]) continue;
					dfs[it.first] = 1;
					qu.push(make_pair(it.first , tp.second + it.second));
					//cout << it.first << " ";
				}
			}
		}
		return 0;
	}
//	for (int i = 1; i <= w; i++){
//		for (auto it : edge[i]){
//			cout << i << " " << it.first << " " << it.second << "\n";
//		}
//	}
	memset(dis , 0x3f , sizeof(dis));
	for (int i = 1; i <= 540; i++){
		dis[i][i] = 0;
	}
	for (int k = 1; k <= w; k++)
	for (int i = 1; i <= w; i++){
		for (int j = 1; j <= w; j++){
			for (auto it : edge[j]){
				dis[i][it.first] = min(dis[i][it.first] , dis[i][j] + it.second);
				dis[it.first][i] = min(dis[it.first][i] , dis[j][i] + it.second);
			}
		}
//		for (int i = 1; i <= w; i++){
//			for (int j = 1; j <= w; j++){
//				cout << dis[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
	}
	while (q--){
		int f , t; cin >> f >> t;
		cout << a[f] + a[t] + dis[f][t] << "\n";
	}
//	for (int i = 1; i <= w; i++){
//		for (int j = 1; j <= w; j++){
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


12 2 4 3 3
1 1 1 1
3 1 2 2 2 3 2
3 2 2 3 2 4 2
1 4
2 3
3 4
*/
