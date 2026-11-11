# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int N = 5e5 + 5;
const int M = 505;
const ll INF = 1e18;
int c, n, m, d, q, w[N];
ll dis[M][M];
vector < pair < int, int>> roads[N];
char buffer[M];
inline void read ( int & x) {
	x = 0;
	char ch = getchar ();
	while ( ! isdigit ( ch)) {
		ch = getchar ();
	}
	while ( isdigit ( ch)) {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
}
inline void write ( ll x) {
	if ( x == 0) {
		putchar ( '0');
		return;
	}
	int it = 0;
	while ( x) {
		buffer[++ it] = x % 10 + '0';
		x /= 10;
	}
	for ( int i = it; i > 0; i --) {
		putchar ( buffer[i]);
	}
}
inline void get_query ( int x, int y) {
    ll ret = INF;
    for ( auto & v : roads[x]) {
        for ( auto & u : roads[y]) {
            ret = min ( ret, dis[v.first][u.first] + v.second + u.second);
        }
    }
//    cout << ret + w[x] + w[y] << endl;
	write ( ret + w[x] + w[y]); putchar ( '\n');
}
signed main () {
	freopen ( "subway.in", "r", stdin); freopen ( "subway.out", "w", stdout);
//    ios :: sync_with_stdio (0); cin.tie (0); cout.tie (0);
//    cin >> c >> n >> m >> d >> q;
    read ( c); read ( n); read ( m); read ( d); read ( q);  
    for ( int i = 1; i <= m; i ++) {
//        cin >> w[i];
		read ( w[i]);
    }
    for ( int i = 1; i <= n; i ++) {
        int len; 
//		cin >> len;
        read ( len);
		for ( int j = 1; j <= len; j ++) {
        	int x, y; 
//			cin >> x >> y;
        	read ( x); read ( y);
			roads[x].push_back ( { i, y});
		}
    }
    for ( int i = 1; i <= n; i ++) {
        for ( int j = 1; j <= n; j ++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for ( int i = 1; i <= m; i ++) {
        for ( int l = 0; l < roads[i].size (); l ++) {
            for ( int r = l + 1; r < roads[i].size (); r ++) {
                int w = roads[i][l].second + roads[i][r].second;
                int u = roads[i][l].first, v = roads[i][r].first;
                if ( dis[u][v] > w) {
                    dis[u][v] = dis[v][u] = w;
                }
            }
        }
    }
    for ( int mid = 1; mid <= n; mid ++) {
        for ( int i = 1; i <= n; i ++) {
            for ( int j = 1; j <= n; j ++) {
                if ( dis[i][j] > dis[i][mid] + dis[mid][j]) {
                    dis[i][j] = dis[i][mid] + dis[mid][j];
                }
            }
        }
    }
    for ( int i = 1; i <= q; i ++) {
        int x, y; 
//		cin >> x >> y;
        read ( x); read ( y);
		get_query ( x, y);
    }
}


