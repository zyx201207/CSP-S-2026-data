#include <bits/stdc++.h>
using namespace std;
#define int long long
const int BUF = 1 << 20;
char ibuf[BUF], *p1 = ibuf, *p2 = ibuf;
inline char gc(){
	return (p1 == p2) && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 20, stdin), p1 == p2) ? EOF : (*p1++);
}
template <typename T>
inline void rd(T& x){
	x = 0;
	bool fl = 0;
	char c = gc();
	for (;!isdigit(c);c = gc())if (c == '-')fl = 1;
	for (;isdigit(c);c = gc())x = (x << 3) + (x << 1) + (c - '0');
	if (fl)x = -x;
}
typedef pair <int, int> pii;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, tot, g[N][N], ans, w[M];
vector <pii> s[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	rd(c), rd(n), rd(m), rd(d), rd(q);
	for (int i = 1;i <= n;i++)for (int j = 1;j <= n;j++)g[i][j] = LLONG_MAX;
	for (int i = 1;i <= n;i++)g[i][i] = 0;
	for (int i = 1;i <= m;i++)rd(w[i]);
	for (int i = 1, len;i <= n;i++){
		rd(len);
		for (int j = 1, x, y;j <= len;j++){
			rd(x), rd(y);
			s[x].push_back({i, y});
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 0;j < s[i].size();j++){
			for (int k = j + 1;k < s[i].size();k++){
				g[s[i][j].first][s[i][k].first] = min(g[s[i][j].first][s[i][k].first], s[i][j].second + s[i][k].second);
				g[s[i][k].first][s[i][j].first] = g[s[i][j].first][s[i][k].first];
			}
		}
	}
//	cout << "#" << g[2][2] << "\n";
	for (int k = 1;k <= n;k++){
		for (int x = 1;x <= n;x++){
			for (int y = 1;y <= n;y++){
				if (g[x][k] ^ LLONG_MAX && g[y][k] ^ LLONG_MAX){
					g[x][y] = min(g[x][y], g[x][k] + g[k][y]);
					g[y][x] = g[x][y];	
				}
			}
		}
	}
//	cout << "#" << g[2][2] << "\n";
	for (int i = 1, x, y;i <= q;i++){
		rd(x), rd(y);
		ans = LLONG_MAX;
//		cout << "!" << s[x].size() << " " << s[y].size() << "\n";
		for (int j = 0;j < s[x].size();j++){
			for (int k = 0;k < s[y].size();k++){
//				cout << "@" << s[x][j].first << " " << s[y][k].first << "\n";
//				cout << "%" << s[x][j].second + s[y][k].second << "\n";
				ans = min(ans, s[x][j].second + s[y][k].second + g[s[x][j].first][s[y][k].first]);
			}
		}
//		cout << ans << "\n"; 
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
