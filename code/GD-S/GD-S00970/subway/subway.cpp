#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<vector<ll> > g(1005,vector<ll>(1005,INF));
int c,n,m,d,que;
vector<int> w(505),vis(505);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin >> c >> n >> m >> d >> que;
	
	for(int i = 1;i <= m;++i){
		cin >> w[i];
	}
	
	for(int i = 1;i <= n;++i){
		int k;
		cin >> k;
		int a[k + 5],t[k + 5];
		for(int j = 1;j <= k;++j){
			cin >> a[j] >> t[j];
		}
		for(int j = 1;j < k;++j){
			int he = t[j] + t[j + 1];
			if(he < g[a[j]][a[j + 1]]){
				g[a[j]][a[j + 1]] = he;
			    g[a[j + 1]][a[j]] = he;
			}
		}
	}
	
	for(int i = 0;i <= m;++i){
		g[i][i] = 0;
	}
	
	for(int k = 1;k <= m;++k){
		for(int i = 1;i <= m;++i){
			for(int j = 1;j <= m;++j){
				g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
			}
		}
	}
	
	for(int i = 1;i <= que;++i){
		int x,y;
		cin >> x >> y;
		ll ans = w[x] + w[y] + g[x][y];
		cout << ans << "\n";
	}
	return 0;
} 
