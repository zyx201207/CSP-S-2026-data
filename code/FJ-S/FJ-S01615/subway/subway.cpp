#include<bits/stdc++.h>
using namespace std ;
long long c ,n ,m ,d ,q ;
long long m1[500005] ;
vector<pair<long long ,long long >> y[500005] ;
long long r[505][505] ;
long long dis[505][505] ;
int main() {
	freopen("subway.in" ,"r" ,stdin ) ;
	freopen("subway.out" ,"w" ,stdout ) ;
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ;i <= m ;i++ ) {
		cin >> m1[i] ;
	}
	for(long long i = 1 ;i <= n ;i++ ) {
		int ki ;
		cin >> ki ;
		for(int j = 1 ;j <= ki ;j++ ) {
			long long v ,u ;
			cin >> v >> u ;
			y[v].push_back({i ,u}) ;
		}
	}
	memset(r ,0x3f ,sizeof r ) ;
	for(int i = 1 ;i <= m ;i++ ) {
		for(int j = 0 ;j < y[i].size() ;j++ ) {
			for(int l = j + 1 ;l < y[i].size() ;l++ ) {
				r[y[i][j].first][y[i][l].first] = min(r[y[i][j].first][y[i][l].first] ,y[i][j].second + y[i][l].second ) ;
				r[y[i][l].first][y[i][j].first] = min(r[y[i][l].first][y[i][j].first] ,y[i][j].second + y[i][l].second ) ;
			}
		}
	}
	for(int t = 1 ;t <= n ;t++ ) {
		bool f[505] ;
		memset(f ,0 ,sizeof f) ;
		for(int i = 0 ;i <= n ;i++ ) {
			dis[t][i] = 0x3f3f3f3f ;
		}
		dis[t][t] = 0 ;
		for(int k = 1 ;k <= n ;k++ ) {
			int t1 = -1 ;
			for(int i = 1 ;i <= n ;i++ ) {
				if((t1 == -1 || dis[t][t1] > dis[t][i] ) && f[i] == 0) t1 = i ;
			}
			f[t1] = 1 ;
			for(int i = 1 ;i <= n ;i++ ) {
				dis[t][i] = min(dis[t][i] ,dis[t][t1] + r[t1][i]) ;
			}
		}
	}
	while(q-- ) {
		long long x ,y1 ;
		cin >> x >> y1 ;
		long long sum = INT_MAX ;
		for(int i = 0 ;i < y[x].size() ;i++ ) {
			for(int j = 0 ;j < y[y1].size() ;j++ ) {
				sum = min(dis[y[x][i].first][y[y1][j].first] + y[x][i].second + y[y1][j].second ,sum ) ; 
			}
		}
		sum += (m1[x] + m1[y1]) ;
		cout << sum << endl ;
	} 
	return 0 ;
}
