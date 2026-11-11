#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10, M = 5e5 + 10;
const long long inf = 9999999999999999ll;
#define pi pair<long long, long long>
long long n, m, d, q, x, y, c, w[M], dis[N][N];
vector<pi> ad[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i = -~i) cin>>w[i];
	for(int i = 1;i <= n;i = -~i){
		cin>>c;
		while(c --) cin>>x>>y, ad[x].emplace_back(pi{i, y});
	}
	for(int i = 1;i <= n;i = -~i){
		for(int j = 1;j <= n;j = -~j) dis[i][j] = (i == j ? 0 : inf);
	}
	for(int i = 1;i <= m;i = -~i){
		for(pi v1 : ad[i]){
			for(pi v2 : ad[i]) dis[v1.first][v2.first] = min(dis[v1.first][v2.first], v1.second + v2.second);
		}
	}
	for(int i = 1;i <= n;i = -~i){
		for(int j = 1;j <= n;j = -~j){
			for(int k = 1;k <= n;k = -~k) dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
		}
	}
	for(int i = 1;i <= q;i = -~i){
		cin>>x>>y, c = inf;
		for(pi v1 : ad[x]){
			for(pi v2 : ad[y]) c = min(c, v1.second + v2.second + dis[v1.first][v2.first]);
		}
		cout<<c + w[x] + w[y]<<'\n';
	}
	return 0;
} 
