#include<bits/stdc++.h>
using namespace std;
const long long N = 550,M = 5e6 + 10;
map<long long,map<long long,long long> > vis;
long long c,n,m,D,q,w[M],k[M],a,U,V,ans,t[N][N],x,y,d[N][N];
vector<vector<long long> > v(M);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++){
			cin >> a >> t[i][j];
			vis[i][a] = j;
			v[a].push_back(i);
		}
	}
	memset(d,0x3f3f3f3f3f3f3f3f,sizeof(long long) * (N * N));
	for(int i = 1;i <= n;i ++){
		d[i][i] = 0;
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 0;j < (int)v[i].size();j ++){
			for(int k = j + 1;k < (int)v[i].size();k ++){
				U = v[i][j];V = v[i][k];
				d[U][V] = min(d[U][V],t[U][vis[U][i]] + t[V][vis[V][i]]);
				d[V][U] = min(d[U][V],d[V][U]);
//				cout << i << " " << U << " " << V << " " << t[U][vis[U][i]] << " " << t[V][vis[V][i]] << '\n';
			}
		}
	}
	
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
//	for(int i = 1;i <= n;i ++){
//		for(int j = 1;j <= n;j ++){
//			cout << d[i][j] << " ";
//		}cout << '\n';
//	}
//	for(int i = 1;i <= m;i ++){
//		for(int j = 0;j < (int)v[i].size();j ++){
//			cout << v[i][j] << " ";
//		}cout << '\n';
//	}
	for(int i = 1;i <= q;i ++){
		cin >> x >> y;
		ans = 0x3f3f3f3f3f3f;
		for(int j = 0;j < (int)v[x].size();j ++){
			for(int k = 0;k < (int)v[y].size();k ++){
				U = v[x][j];V = v[y][k];
//				cout << U << " " << V << '\n';
				ans = min(ans,d[U][V] + t[U][vis[U][x]] + t[V][vis[V][y]]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	
	return 0;
}
