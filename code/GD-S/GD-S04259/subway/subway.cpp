#include <bits/stdc++.h>

#define int long long 

using namespace std;
const int N = 3e4 + 10, M = 3010;
int read () {
	int val = 0, f = 1;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())
	    if (c == '-') f = -1;
	for (; c >= '0' && c <= '9'; c = getchar())
	    val = (val << 1) + (val << 3) + (c ^ 48);
	return val * f;
}
void write (int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write (x / 10);
	putchar (x % 10 + '0');
}
int c, n, m, d, q, w[M], k[M], a[510][N], t[510][N], x, y;
int dis[M][M], ds[M][M], dsk[N];
vector <int> p[N];
typedef pair <int, int> P;
priority_queue <P, vector <P>, greater <P> > qr; 
void Dijkstra (int s) {
	memset (ds[s], 0x3f3f3f3f, sizeof (ds[s]));
	ds[s][s] = 0;
	qr.push (make_pair (0, s));
	while (!qr.empty()) {
		int x = qr.top().first, y = qr.top().second;
		qr.pop();
		if (ds[s][y] != x) continue;
		for (int i : p[y]) {
			for (int j = 1; j <= k[i]; j++)
			    if (a[i][j] != y) {
			       if (ds[s][a[i][j]] > ds[s][y] + t[i][a[i][j]] + t[i][y])
			          ds[s][a[i][j]] = ds[s][y] + t[i][a[i][j]] + t[i][y], qr.push (make_pair (ds[s][a[i][j]], a[i][j]));
				}
		}
	}
	while (!qr.empty()) qr.pop();
}
void Dijkstra1 (int s, int ed) {
	memset (dsk, 0x3f3f3f3f, sizeof (dsk));
	dsk[s] = 0;
	qr.push (make_pair (0, s));
	while (!qr.empty()) {
		int x = qr.top().first, y = qr.top().second;
		qr.pop();
		if (dsk[y] != x) continue;
		for (int i : p[y]) {
			for (int j = 1; j <= k[i]; j++)
			    if (a[i][j] != y) {
			       if (dsk[a[i][j]] > dsk[y] + t[i][a[i][j]] + t[i][y])
			          dsk[a[i][j]] = dsk[y] + t[i][a[i][j]] + t[i][y], qr.push (make_pair (dsk[a[i][j]], a[i][j]));
				}
		}
	}
	write(dsk[ed] + w[s] + w[ed]);
	putchar('\n');
	while (!qr.empty()) qr.pop();
}
signed main() {
    
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    memset (dis, 0x3f3f3f3f, sizeof (dis));
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
    	k[i] = read();
    	for (int j = 1; j <= k[i]; j++) a[i][j] = read(), t[i][a[i][j]] = read(), p[a[i][j]].emplace_back (i);
	}

    if (m <= 2010) {
       for (int i = 1; i <= m; i++) Dijkstra (i);
	   while (q--) {
		x = read(), y = read();
		write (ds[x][y] + w[x] + w[y]);
		putchar('\n');
       } 
	} else {
	   while (q--) {
	   	x = read(), y = read();
	   	Dijkstra1 (x, y);
	   }
	}
   
	return 0;
}


