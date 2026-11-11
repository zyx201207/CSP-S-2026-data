#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 505,M = 5e5 + 5;
int n,m,d,q,w[M],k,x,y,dis[N][N];
vector<pair<int,int>> v[M]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef LOCAL
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	cin >> n >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k;
		while(k--){
			cin >> x >> y;
			v[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		for(auto j : v[i]){
			for(auto k : v[i])if(j.first != k.first){
				dis[j.first][k.first] = min(dis[j.first][k.first],j.second + k.second);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++)dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
		}
	}
	while(q--){
		cin >> x >> y;
		int ans = 1e18;
		for(auto i : v[x]){
			for(auto j : v[y]){
				ans = min(ans,dis[i.first][j.first] + i.second + j.second);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
}
