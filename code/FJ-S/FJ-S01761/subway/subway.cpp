#include <bits/stdc++.h>
#define int long long
// CCF shen ji wo zhen qiu ni le (Why can't this computer input Chinese?)
// is 1s 3.65e8 OK? 

using namespace std;

const int N = 505,M = 5e5+5;
int cid,n,m,w[M],D,q,d[N][N];
struct Edge{
	int to,w;
};
vector<Edge> v[M];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(d,0x3f,sizeof d);
	cin >> cid >> n >> m >> D >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int a,t;
			cin >> a >> t;
			v[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= n;i++){
		d[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < v[i].size();j++){
			for(int k = j+1;k < v[i].size();k++){
				d[v[i][j].to][v[i][k].to] = d[v[i][k].to][v[i][j].to] = min(d[v[i][k].to][v[i][j].to],v[i][j].w + v[i][k].w);
//				cout << v[i][j].w + v[i][k].w << '\n';
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= n;j++){
//			cout << d[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	while(q--){
		int x,y,ans = LLONG_MAX;
		cin >> x >> y;
		for(int i = 0;i < v[x].size();i++){
			for(int j = 0;j < v[y].size();j++){
				ans = min(ans,w[x] + w[y] + v[x][i].w + d[v[x][i].to][v[y][j].to] + v[y][j].w);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}