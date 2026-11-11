#include<bits/stdc++.h>
#define N 500005
#define M 505
#define ll long long
#define pii pair<int,int>
#define inf 1000000000000000000ll
using namespace std;
int c,n,m,d,q,w[N];
vector<pii> dat[N];
ll dp[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		while(k --){
			int x,y;
			cin >> x >> y;
			dat[x].push_back({i,y});
		}
		for(int j = 1;j <= n;j ++){
			dp[i][j] = inf;
		}
		dp[i][i] = 0;
	}
	for(int i = 1;i <= m;i ++){
		for(pii j : dat[i]){
			for(pii k : dat[i]){
				int u = j.first,v = k.first;
				ll w = j.second + k.second;
				dp[u][v] = min(dp[u][v],w);
			}
		}
	}
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		}
	}
	while(q --){
		int u,v;
		cin >> u >> v;
		ll minn = inf;
		for(pii i : dat[u]){
			for(pii j : dat[v]){
				minn = min(minn,1ll * i.second + 1ll * j.second + dp[i.first][j.first]);
			}
		}
		cout << minn + 1ll * w[u] + 1ll * w[v] << "\n";
	}
	return 0;
}

