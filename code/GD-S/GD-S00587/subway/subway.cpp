#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int k[N],w[N],a[N][505],t[N][505];
vector<int> adj[N]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			adj[j].push_back(i);
		}
	}
	for(int i = 1;i <= q;i++){
		int ans = 0;
		int x, y;
		cin >> x >> y;
		for(int j = 1;j <= n;j++){
			if(t[x][j] == 0|| t[y][j] == 0) continue;
			ans = min(ans,t[x][j] + t[y][j]);
		}
		cout << w[x] + ans + w[y] << '\n';
	}
}
