#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c, t;
int dfn[N], low[N];
vector<pair<int, int>> g[N];
void tarjan(){
	
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t -- ){
		int n, k;
		cin >> n >> k;
		for(int i = 1, x, y; i <= n - 1; i ++ ){
			cin >> x >> y;
			g[i].push({x, y});
		}
	}
	return 0;
}
